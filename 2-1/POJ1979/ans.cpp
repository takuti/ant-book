#include <stdio.h>

#define ROOM_SIZE 20

int solve(int w, int h, char tiles[][ROOM_SIZE], int x, int y) {
  if (x < 0 || w <= x || y < 0 || h <= y) return 0;
  if (tiles[y][x] != '.') return 0;
  tiles[y][x] = '!';

  return (solve(w, h, tiles, x - 1, y) +
          solve(w, h, tiles, x + 1, y) +
          solve(w, h, tiles, x, y - 1) +
          solve(w, h, tiles, x, y + 1) +
          1);
}

int main() {
  while(true) {
    int w, h, sx, sy;
    scanf(" %d %d", &w, &h);

    if (w == 0 && h == 0) break;

    char tiles[ROOM_SIZE][ROOM_SIZE];
    for (int i = 0; i < h; i++) {
      scanf(" %s", tiles[i]);
      for (int j = 0; j < w; j++) {
        if (tiles[i][j] == '@') {
          sy = i;
          sx = j;
          tiles[i][j] = '.';
        }
      }
    }

    printf("%d\n", solve(w, h, tiles, sx, sy));
  }
  return 0;
}
