#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

struct period {
  int start;
  int end;
  int efficiency;

  bool operator < (const period& right) const {
    return start < right.start;
  }
};

int N, M, R;
period input[1000];
int dp[1000][1000];
int resting_time[1000];

int solve() {
  sort(input, input + M);

  for (int i = 0; i < M; i++) {
    if (i > 0) {
      for (int j = 0; j < M; j++) {
        dp[i][j] = dp[i - 1][j];
      }
    }

    int current_max = 0;
    for (int j = 0; j < M; j++) {
      resting_time[j] -= input[i].start - input[i - 1].start;
      if (resting_time[j] <= 0 && dp[i][j] > current_max) {
        current_max = dp[i][j];
      }
    }

    dp[i][i] = current_max + input[i].efficiency;
    resting_time[i] = R + input[i].end - input[i].start;
  }

  int result = 0;
  for (int j = 0; j < M; j++) {
    if (dp[M - 1][j] > result) {
      result = dp[M - 1][j];
    }
  }
  return result;
}

int main() {
  scanf("%d %d %d", &N, &M, &R);
  for (int i = 0; i < M; i++) {
    scanf("%d %d %d", &input[i].start, &input[i].end, &input[i].efficiency);
  }
  printf("%d\n", solve());
  return 0;
}
