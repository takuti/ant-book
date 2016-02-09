#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX_N = 400;
int dp[MAX_N][MAX_N];
int cows[MAX_N][MAX_N];
int N;

int solve() {
  for (int i = 1; i <= N; i++) {
    dp[i][0] = dp[i-1][0] + cows[i-1][0];
    int j = 1;
    for (j = 1; j < i-1; j++) dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + cows[i-1][j];
    dp[i][j] = dp[i-1][j-1] + cows[i-1][j];
  }
  int res = -1;
  for (int j = 0; j < N; j++) res = max(res, dp[N][j]);
  return res;
}

int main() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++)
    for (int j = 0; j < i+1; j++) scanf("%d", &cows[i][j]);
  printf("%d\n", solve());
  return 0;
}
