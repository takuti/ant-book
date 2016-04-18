#include <iostream>

using namespace std;

int n, m;
int a[100];
int c[100];
int dp[100000];

int main() {
  while (true) {
    // input
    cin >> n >> m;
    if (n == 0 && m == 0) break;

    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
      cin >> c[i];
    }

    for (int i = 0; i < m; i++) {
      dp[i] = -1;
    }

    // DP
    // dp[i][j] = 1~i 番目の硬貨で金額 j を作った時に余る i 番目の硬貨の枚数
    // 蟻本の 62-63p あたり
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (dp[j] >= 0) {
          dp[j] = c[i];
        } else if (j + 1 == a[i]) {
          dp[j] = c[i] - 1;
        } else if (j < a[i] || dp[j - a[i]] <= 0) {
          dp[j] = -1;
        } else {
          dp[j] = dp[j - a[i]] - 1;
        }
      }
    }

    // output
    int result = 0;
    for (int i = 0; i < m; i++) {
      result += dp[i] != -1 ? 1 : 0;
    }
    cout << result << endl;
  }
  return 0;
}
