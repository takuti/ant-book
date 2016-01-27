#include <stdio.h>
#include <queue>

#define MAP_SIZE_MAX 1001
#define INF 100000000

typedef std::pair<int, int> point;

int get_time(int sx, int sy, int goal,
                 int h, int w, char map[][MAP_SIZE_MAX],
                 int *gx, int *gy) {
  std::queue<point> queue;
  queue.push(point(sx, sy));

  // initalize time array
  int time[MAP_SIZE_MAX][MAP_SIZE_MAX];
  for (int i = 0; i < MAP_SIZE_MAX; i++) {
    for (int j = 0; j < MAP_SIZE_MAX; j++) {
      time[i][j] = INF;
    }
  }
  time[sx][sy] = 0;

  // 幅優先探索
  while (true) {
    point current = queue.front();
    queue.pop();
    int x = current.first;
    int y = current.second;

    // goal!
    if (map[x][y] == goal + '0') {
      *gx = x;
      *gy = y;
      return time[x][y];
    }

    // 4 方向に進む
    int d[] = { 0, 1, 0, -1, 0 };
    for (int i = 0; i < 4; i++) {
      int _x = x + d[i];
      int _y = y + d[i + 1];
      if (map[_x][_y] != 'X' &&
          time[_x][_y] == INF &&
          0 <= _x && _x < h && 0 <= _y && _y < w) {
        time[_x][_y] = time[x][y] + 1;
        queue.push(point(_x, _y));
      }
    }
  }
}

int solve(int h, int w, int n, char map[][MAP_SIZE_MAX]) {
  // find start position
  int sx, sy, gx, gy;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (map[i][j] == 'S') {
        sx = i;
        sy = j;
        break;
      }
    }
  }

  int result = 0;
  for (int i = 1; i <= n; i++) {
    result += get_time(sx, sy, i, h, w, map, &gx, &gy);

    // ゴール位置が次のスタート位置
    sx = gx;
    sy = gy;
  }

  return result;
}

int main() {
  int h, w, n;
  scanf("%d %d %d", &h, &w, &n);

  char map[MAP_SIZE_MAX][MAP_SIZE_MAX];
  for (int i = 0; i < h; i++) {
    scanf("%s", map[i]);
  }

  printf("%d\n", solve(h, w, n, map));

  return 0;
}
