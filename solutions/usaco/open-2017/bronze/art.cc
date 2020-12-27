#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "../../_library/cc/debug.h"
#define FILE "test"
#else
#define debug(...) 0
#define FILE "art"
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int N;
  cin >> N;
  vector<array<int, 4>> bounds(10);
  fill(bounds.begin(), bounds.end(),
       array<int, 4>{INT_MAX, INT_MAX, INT_MIN, INT_MIN});

  auto cmin = [](int& x, int y) { x = min(x, y); };
  auto cmax = [](int& x, int y) { x = max(x, y); };

  vector<vector<int>> grid(N, vector<int>(N));
  vector<bool> pos(10);
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      char c;
      cin >> c;
      c -= '0';
      grid[i][j] = c;
      pos[c] = true;
      cmin(bounds[c][0], i);
      cmin(bounds[c][1], j);
      cmax(bounds[c][2], i);
      cmax(bounds[c][3], j);
    }
  }

  for (int i = 1; i < 10; ++i) {
    for (int j = bounds[i][0]; j <= bounds[i][2]; ++j) {
      for (int k = bounds[i][1]; k <= bounds[i][3]; ++k) {
        if (grid[j][k] != i) {
          pos[grid[j][k]] = false;
        }
      }
    }
  }
  cout << accumulate(pos.begin() + 1, pos.end(), 0);
}
