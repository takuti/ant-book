#include <cstdio>
#include <algorithm>

// start * (start + 1) * (start + 2) * ... * (n - 1) * n
int factorial(int n, int start=1) {
  int result = 1;
  if (n == 0) return 1;
  for (int i = start; i <= n; i++) {
    result *= i;
  }
  return result;
}

// n! / (k! * (n - k)!)
int binomial(int n, int k) {
  return factorial(n, k + 1) / factorial(n - k);
}

int main() {
  int n, sum;
  int nums[10];

  scanf("%d %d", &n, &sum);
  for (int i = 0; i < n; i++) nums[i] = i + 1;

  do {
    int current_sum = 0;
    for (int i = 0; i < n; i++) {
      current_sum += binomial(n - 1, i) * nums[i];
    }

    if (current_sum == sum) {
      break;
    }
  } while(std::next_permutation(nums, nums + n));

  // output
  for (int i = 0; i < n; i++) {
    if (i > 0) printf(" ");
    printf("%d", nums[i]);
  }
  printf("\n");

  return 0;
}
