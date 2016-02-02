#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <functional>
#include <climits>
#include <cstdio>

using namespace std;

int solve(int c, map<int, int> &coins) {
  int week = 0;
  while (true) {
    int paid = 0;
    std::map<int, int> optimal;
    int min = INT_MAX;

    // 大きい額の硬貨から見る
    for (map<int, int>::reverse_iterator it = coins.rbegin();
         it != coins.rend();
         it++) {
      while (it->second > 0) {
        // it->first の硬化を出す
        coins[it->first]--;
        paid += it->first;

        if (c == paid) {
          // c 丁度であれば break
          optimal = coins;
          min = paid;
          break;
        } else if (c < paid) {
          // c を超えた場合、paid の最小値を採用
          if (paid < min) {
            optimal = coins;
            min = paid;
          }
          // 別の支払い方を探すため、硬貨を戻す
          coins[it->first]++;
          paid -= it->first;
          break;
        }
      }
      if (c == paid) break;
    }
    coins = optimal;
    if (min == INT_MAX) break;
    week++;
  }

  return week;
}

int main() {
  int n, c;
  int w = 0;
  map<int, int> coins;
  scanf("%d %d", &n, &c);
  for (int i = 0; i < n; i++) {
    int v, b;
    scanf("%d %d", &v, &b);
    if (v < c) {
      coins[v] = b;
    } else {
      // 週の支払いより大きい額の硬貨は 1 枚で使う
      w += b;
    }
  }
  printf("%d\n", w + solve(c, coins));
}
