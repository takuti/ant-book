#include <iostream>

typedef unsigned long long ull;

struct BigInt {
public:
  ull hi;
  ull low;
  static const ull mod = 1E18;

  BigInt() {
    hi = 0;
    low = 0;
  }

  BigInt(int value) {
    hi = 0;
    low = value;
  }
};

BigInt add(BigInt a, BigInt b) {
  BigInt result;
  result.low = (a.low + b.low) % BigInt::mod;
  result.hi = (a.hi + b.hi) + (a.low + b.low) / BigInt::mod;
  return result;
}

void print(BigInt value) {
  if (value.hi != 0)
    std::cout << value.hi;
  std::cout << value.low << std::endl;
}

int main() {
  int N, K;
  std::cin >> N >> K;

  BigInt dp[N + 1][K + 1];

  for (int i = 0; i <= N; i++) {
    for (int j = 0; j <= K; j++) {
      dp[i][j] = 1;
    }
  }

  for (int i = 2; i <= N; i++) {
    for (int j = 2; j <= K; j++) {
      dp[i][j] = add(dp[i][j - 1], (i >= j ? dp[i - j][j] : 0));
    }
  }

  print(dp[N][K]);
  return 0;
}
