#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int solve(vector<int> digits) {
  int n = digits.size();
  int min_diff = 1000000000;

  if (n == 2) return digits[1] - digits[0];

  int h = n / 2;
  for (int i = h; i <= h+1; i++) {
    do {
      if (digits[0] == 0 || digits[i] == 0) continue;
      int v1 = 0, v2 = 0;
      for (int j = 0; j < i; j++) v1 = v1 * 10 + digits[j];
      for (int j = i; j < n; j++) v2 = v2 * 10 + digits[j];
      int diff = fabs(v1 - v2);
      if (diff < min_diff) min_diff = diff;
    } while (next_permutation(digits.begin(), digits.end()));
  }

  return min_diff;
}

int main() {
  int n;
  scanf("%d\n", &n);

  for (int i = 0; i < n; i++) {
    vector<int> digits;
    char c;

    while (true) {
      scanf("%c", &c);
      if (c == '\n') break;
      else if (c == ' ') continue;
      digits.push_back(int(c - '0'));
    }

    printf("%d\n", solve(digits));
  }

  return 0;
}
