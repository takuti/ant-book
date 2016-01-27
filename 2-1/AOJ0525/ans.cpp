#include <cstdio>
#include <cmath>
#include <algorithm>

#define R_MAX 10
#define C_MAX 10000

// 列の裏返し状態を 2^r 通り全探索する。
// 煎餅を裏返す順番は無視できるので、
// 列の裏返し状態が決まれば行の裏返し状態は各行で独立に決められる。
// それぞれの行で売れる煎餅数を最大化して、総和を求める。
int solve(int senbeis[R_MAX][C_MAX], int r, int c) {
  int result = 0;

  // 列の裏返し状態を全探索する
  // i の n bit 目が 1 のとき n-th row をひっくり返したとみなす
  int bitMax = pow(2, r);
  for (int i = 0; i < bitMax; i++) {
    int baked = 0; // 売れる煎餅の数
    for (int j = 0; j < c; j++) {
      int front_senbei = 0; // 表向きの煎餅数
      for (int k = 0; k < r; k++) {
        // i の k-th bit を取り出して、1 なら senbeis[k][j] の 0,1 を反転
        front_senbei += (senbeis[k][j] ^ (i >> k & 1));
      }
      baked += std::max(front_senbei, r - front_senbei);
    }
    result = std::max(result, baked);
  }
  return result;
}

int main() {
  while (true) {
    int senbeis[R_MAX][C_MAX];
    int r, c;

    // input
    scanf(" %d %d", &r, &c);
    if (r == 0 || c == 0) break;
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        scanf("%d", &senbeis[i][j]);
      }
    }

    // output
    printf("%d\n", solve(senbeis, r, c));
  }

  return 0;
}
