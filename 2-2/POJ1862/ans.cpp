#include <cstdio>
#include <cmath>
#include <queue>
using namespace std;

#define COLLIDE(m1, m2) (2*sqrt(m1*m2))

priority_queue <float> weights;

float solve() {
  while (true) {
    float m1 = weights.top(); weights.pop();
    if (weights.empty()) return m1;
    float m2 = weights.top(); weights.pop();
    float m_ = COLLIDE(m1, m2);
    weights.push(m_);
  }
}

int main() {
  int N;
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    float m;
    scanf("%f", &m);
    weights.push(m);
  }
  printf("%.3f\n", solve());
  return 0;
}
