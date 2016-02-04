#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

typedef pair<int,int> interval;
int interval::* from = &interval::first;
int interval::* to = &interval::second;

typedef pair<interval, int> cow;
interval cow::* milk = &cow::first;
int cow::* idx = &cow::second;

struct comparator {
  bool operator() (const cow& l, const cow& r) {
    return l.*milk.*to > r.*milk.*to;
  }
};

const int MAX_COWS = 50000;
int N, n_stall;
cow cows[MAX_COWS];
priority_queue<cow, vector<cow>, comparator> stall_tails;

void solve(int ans[]) {
  sort(cows, cows+N);
  for (int i = 0; i < N; i++) {
    if (stall_tails.empty() || stall_tails.top().*milk.*to >= cows[i].*milk.*from) {
      n_stall++;
      ans[cows[i].*idx] = n_stall;
    } else {
      cow c = stall_tails.top();
      stall_tails.pop();
      ans[cows[i].*idx] = ans[c.*idx];
    }
    stall_tails.push(cows[i]);
  }
}

int main() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%d %d", &(cows[i].*milk.*from), &(cows[i].*milk.*to));
    cows[i].*idx = i;
  }

  int ans[N];
  solve(ans);
  printf("%d\n", n_stall);
  for (int i = 0; i < N; i++) printf("%d\n", ans[i]);

  return 0;
}
