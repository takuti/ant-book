#include <cstdio>
#include <cmath>
using namespace std;

#define S(size) ((size) * (size))

int solve(int n_packages[7]) {
  int ans = n_packages[6];
  if (n_packages[5] > 0) {
    ans += n_packages[5];
    // remaining spaces can be filled by size=1 packages
    n_packages[1] -= (S(6)-S(5)) * n_packages[5];
  }
  if (n_packages[4] > 0) {
    ans += n_packages[4];
    // can be filled by size=2 an 1
    int free_2x = (S(6)-S(4)) / S(2) * n_packages[4];
    n_packages[2] -= free_2x;
    if (n_packages[2] < 0) n_packages[1] -= abs((float)n_packages[2]) * S(2);
  }
  if (n_packages[3] > 0) {
    int n_3x = S(6) / S(3); // 4
    ans += n_packages[3] / n_3x;
    int free_3x = n_3x - (n_packages[3] % n_3x);
    if (free_3x != n_3x) ans += 1;
    // can be filled by size=2 an 1
    if (free_3x == 1) {
      // 1 3x3 = 1 2x2 + 5 1x1
      n_packages[2] -= 1;
      n_packages[1] -= 5;
    } else if (free_3x == 2) {
      // 2 3x3 = 3 2x2 + 6 1x1
      n_packages[2] -= 3;
      n_packages[1] -= 6;
    } else if (free_3x == 3) {
      // 3 3x3 = 5 2x2 + 7 1x1
      n_packages[2] -= 5;
      n_packages[1] -= 7;
    }
  }
  if (n_packages[2] > 0) {
    int n_2x = S(6) / S(2); // 9
    ans += n_packages[2] / n_2x;
    int free_2x = n_2x - (n_packages[2] % n_2x);
    if (free_2x != n_2x) {
      ans += 1;
      // can be filled by size=1
      n_packages[1] -= S(2) * free_2x;
    }
  }
  if (n_packages[1] > 0) {
    ans += n_packages[1] / S(6);
    if (n_packages[1] % S(6) != 0) ans += 1;
  }

  return ans;
}

int main() {
  int n_packets[7] = {};
  while (true) {
    bool is_null = true;
    for (int size = 1; size <= 6; size++) {
      scanf("%d", &n_packets[size]);
      if (n_packets[size] != 0) is_null = false;
    }
    if (is_null) break;
    printf("%d\n", solve(n_packets));
  }
  return 0;
}
