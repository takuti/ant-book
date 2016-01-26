#include <cstdio>
#include <vector>
#include <queue>
#include <set>

using namespace std;

struct P {
  int x, y;
  vector<char> s;
};

char grid[10][10];
set< vector<char> > s;

int solve() {
  queue<P> que;

  for (int i = 1; i <= 5; i++) {
    for (int j = 1; j <= 5; j++) {
      char init_data[] = {grid[i][j]};
      vector<char> init(init_data, init_data+1);
      P p = {i, j, init};
      que.push(p);
    }
  }

  while (!que.empty()) {
    P p = que.front();
    que.pop();
    if (p.s.size() == 6) {
      s.insert(p.s);
      continue;
    }
    int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
    for (int i = 0; i < 4; i++) {
      P next;
      next.x = p.x + dx[i]; next.y = p.y + dy[i];
      if (grid[next.x][next.y] == '\0') continue;
      next.s = p.s;
      next.s.push_back(grid[next.x][next.y]);
      que.push(next);
    }
  }

  return s.size();
}

int main() {
  for (int i = 1; i <= 5; i++)
    for (int j = 1; j <= 5; j++) scanf("%c ", &grid[i][j]);

  printf("%d\n", solve());

  return 0;
}
