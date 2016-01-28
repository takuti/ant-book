#include <cstdio>

const int MAX_D = 20;
const int INF = 1000;

int solve(int w, int h, int board[][MAX_D+2], int x, int y, int turn) {
  // stone cannot move more than 10 times
  if (turn > 10) return INF;

  int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
  int min_res = INF;

  for (int i = 0; i < 4; i++) {
    // the direction is blocked immediately
    if (board[y + dy[i]][x + dx[i]] == 1) continue;

    int xi = x, yi = y;

    // keep moving
    while (board[yi][xi] == 2) {
      xi += dx[i];
      yi += dy[i];
    }

    // goal
    if (board[yi][xi] == 3) return turn;

    // hit a block
    if (board[yi][xi] == 1) {
      board[yi][xi] = 2; // disappear the hit block
      int res = solve(w, h, board, xi-dx[i], yi-dy[i], turn+1);
      if (min_res > res) min_res = res;
      board[yi][xi] = 1; // back to the previous board
    }
  }

  return min_res;
}

int main() {
  while (true) {
    int w, h;
    scanf("%d %d", &w, &h);

    if (w == 0 && h == 0) break;

    int board[MAX_D+2][MAX_D+2] = {};
    int sx, sy;

    int res;
    for (int y = 1; y <= h; y++) {
      for (int x = 1; x <= w; x++) {
        scanf("%d", &board[y][x]);

        // change 0: vacant -> out of board, 2: start -> vacant
        // (a board is initialized by 0s)
        if (board[y][x] == 0) {
          board[y][x] = 2;
        }
        else if (board[y][x] == 2) {
          sx = x;
          sy = y;
        }
      }
    }

    if ((res = solve(w, h, board, sx, sy, 1)) == INF) res = -1;
    printf("%d\n", res);
  }

  return 0;
}
