#include <cstdio>
#include <cmath>
#include <queue>
#include <map>

struct state {
  int cards;
  int step;

  state(int cards, int step) {
    this->cards = cards;
    this->step = step;
  }
};

// value の digit 桁目の数値を取得
int get_digit(int value, int digit) {
  return (value / (int)pow(10, digit - 1)) % 10;
}

// value の a 桁目と b 桁目の数値を交換
int swap_digit(int value, int a, int b) {
  int _a = get_digit(value, a);
  int _b = get_digit(value, b);
  return value -
    (_a * pow(10, a - 1) + _b * pow(10, b - 1)) +
    (_b * pow(10, a - 1) + _a * pow(10, b - 1));
}

void push_swapped_state(state _state, int z, int y,
                        std::map<int, int> *map,
                        std::queue<state> *queue) {
  int new_cards = swap_digit(_state.cards, z, y);
  if (map->find(new_cards) == map->end()) {
    queue->push(state(new_cards, _state.step + 1));
  }
}

// state => step の key-value map を作る
std::map<int, int> *make_map() {
  std::map<int, int> *result = new std::map<int, int>();
  std::queue<state> queue;
  queue.push(state(1234567, 0));

  while (queue.size() > 0) {
    state _state = queue.front();
    queue.pop();

    (*result)[_state.cards] = _state.step;

    int z = 0; // index of zero
    for (int i = 1; i <= 8; i++) {
      if (get_digit(_state.cards, i) == 0) z = i;
    }

    // swap with left card
    if (z % 4 != 0) {
      push_swapped_state(_state, z, z + 1, result, &queue);
    }

    // swap with right card
    if ((z - 1) % 4 != 0) {
      push_swapped_state(_state, z, z - 1, result, &queue);
    }

    // swap with top card
    if (z < 5) {
      push_swapped_state(_state, z, z + 4, result, &queue);
    }

    // swap with bottom card
    if (z > 4) {
      push_swapped_state(_state, z, z - 4, result, &queue);
    }
  }
  return result;
}

int main() {
  char buf[256];
  std::map<int, int> *steps = make_map();
  while (scanf(" %[^\n]", buf) != EOF) {
    int state = 0;
    int radix = 1;
    for (int i = 7; i >= 0; i--) {
      state += (buf[i * 2] - '0') * radix;
      radix *= 10;
    }
    printf("%d\n", (*steps)[state]);
  }
  delete steps;
  return 0;
}
