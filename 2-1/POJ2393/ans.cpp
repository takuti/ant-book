#include <iostream>
#include <algorithm>
#include <climits>

int main() {
  int n, s;
  int c[10000];
  int y[10000];

  // input
  std::cin >> n >> s;
  for (int i = 0; i < n; i++) {
    std::cin >> c[i] >> y[i];
  }

  // solve
  unsigned long long result = 0;
  for (int i = 0; i < n; i++) {
    int min_cost = INT_MAX;
    for (int j = 0; j <= i; j++) {
      int j_cost = c[j] + s * (i - j);
      min_cost = std::min(min_cost, j_cost);
    }
    result += y[i] * min_cost;
  }

  // output
  std::cout << result << std::endl;
  return 0;
}
