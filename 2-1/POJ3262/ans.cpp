#include <cstdio>
#include <vector>
#include <algorithm>

typedef unsigned long long ull;

using namespace std;

ull solve(int n, int t[], int d[]) {
  vector<pair<double, int> > m;
  ull dps = 0; // destroy per seconds
  ull result = 0;

  for (int i = 0; i < n; i++) {
    m.push_back(make_pair(-d[i] / (double)t[i], i));
    dps += d[i];
  }

  sort(m.begin(), m.end());

  vector<pair<double, int> >::iterator it = m.begin();
  while (it != m.end()) {
    dps -= d[it->second];
    result += 2 * dps * t[it->second];
    it++;
  }
  return result;
}

int main() {
  int n;
  int t[100000];
  int d[100000];
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &t[i], &d[i]);
  }
  printf("%lld\n", solve(n, t, d));
  return 0;
}
