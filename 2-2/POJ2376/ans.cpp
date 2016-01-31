#include <cstdio>
#include <algorithm>
using namespace std;

typedef pair<int,int> interval;

const int MAX_COWS = 25000;
int N, T;
interval cows[MAX_COWS];

int solve() {
  sort(cows, cows+N);
  int i = 0, i_ = 0, cnt = 0, covered = 0;
  while (true) {
    bool possible = false;
    while (i < N) {
      if (cows[i].first > covered+1) break;
      if (cows[i].second > cows[i_].second) i_ = i;
      possible = true;
      i++;
    }
    cnt++;
    if ((covered = cows[i_].second) >= T) break;
    else if (!possible || i == N) return -1;
  }
  return cnt;
}

int main() {
  scanf("%d %d", &N, &T);
  for (int i = 0; i < N; i++) scanf("%d %d", &cows[i].first, &cows[i].second);
  printf("%d\n", solve());
  return 0;
}
