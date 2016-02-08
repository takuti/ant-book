#include <iostream>
#include <cmath>

using namespace std;

int n;
int pow2[22];
int dp[22][1000002];
// dp[i][j] := 0^2 ~ i^2 を使って j を作ることができるパターン数

int main() {
  cin >> n;

  // initialize pow2 array
  for (int i = 0; i < 22; i++) {
    pow2[i] = (int)pow(2, i);
  }

  // 0^2 == 1 のみを用いて j を作るパターンは必ず 1
  for (int j = 0; j <= n; j++) {
    dp[0][j] = 1;
  }

  // 便宜上 1 にする
  for (int i = 0; i < 22; i++) {
    dp[i][0] = 1;
  }

  for (int i = 1; i < 22; i++) {
    for (int j = 1; j <= n; j++) {
      dp[i][j] = dp[i - 1][j];
      if (pow2[i] <= j) {
        dp[i][j] += dp[i][j - pow2[i]];
      }
      dp[i][j] %= 1000000000;
    }
  }

  cout << dp[21][n] << endl;

  return 0;
}
