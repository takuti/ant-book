#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

struct P {
  int x, y;
  double radar_x;
};

int pow(int x) { return x * x; }

bool compare(P a, P b) {
  return a.radar_x < b.radar_x;
}

int solve(int n, int d, P islands[]) {
  int radar = 0;

  // sort islands
  sort(islands, islands + n, compare);

  for (int i = 0; i < n; i++) {
    int x = islands[i].x;
    int y = islands[i].y;
    double radar_x = islands[i].radar_x;

    if (y > d) return -1;

    // install radar
    radar++;

    while (i + 1 < n &&
      pow(radar_x - islands[i + 1].x, 2) + pow(islands[i + 1].y, 2) <= pow(d, 2)) {
      i++;
    }
  }
  return radar;
}

int main() {
  int n, d;
  for (int i = 0; true; i++) {
    P islands[1001] = {};
    cin >> n >> d;
    if (n == 0) break;
    for (int j = 0; j < n; j++) {
      cin >> islands[j].x >> islands[j].y;

      // radar_x is rightmost radar location that can capture islands[j]
      islands[j].radar_x = islands[j].x + sqrt(d * d - islands[j].y * islands[j].y);
    }
    cout << "Case " << i + 1 << ": "
         << solve(n, d, islands) << std::endl;
  }
  return 0;
}
