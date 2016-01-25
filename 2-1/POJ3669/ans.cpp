#include <cstdio>
#include <queue>

using namespace std;

struct P {
  int x, y, t;
};

const int L = 300;
const int INF = 10000;
int plane[L+3][L+3];
int max_t;

int solve() {
  queue<P> que;

  // initial position
  P init = {1, 1, 0};
  que.push(init);

  int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
  int visited[L+3][L+3] = {};

  while (!que.empty()) {
    P current = que.front();
    que.pop();

    int x = current.x;
    int y = current.y;
    int t = current.t;

    if (plane[x][y] <= t) continue; // hit a meteor
    if (plane[x][y] == INF || t == max_t) return t;

    int t_ = t + 1;
    for (int i = 0; i < 4; i++) {
      int x_ = x + dx[i];
      int y_ = y + dy[i];
      P next = {x_, y_, t_};
      if (x_ >= 1 && y_ >= 1 && visited[x_][y_] == 0) {
        visited[x_][y_] = 1;
        que.push(next);
      }
    }
  }

  return -1;
}

int main() {
  for (int i = 0; i < L+3; i++) fill_n(plane[i], L+3, INF);

  int M;
  scanf("%d", &M);

  int dx[] = {0, 1, -1, 0, 0}, dy[] = {0, 0, 0, 1, -1};
  max_t = -1;

  for (int i = 0; i < M; i++) {
    int x, y, t;
    scanf("%d %d %d", &x, &y, &t);
    if (t > max_t) max_t = t;
    x += 1; y += 1;
    for (int j = 0; j < 5; j++) {
      if (plane[x+dx[j]][y+dy[j]] > t) plane[x+dx[j]][y+dy[j]] = t;
    }
  }

  printf("%d\n", solve());

  return 0;
}
