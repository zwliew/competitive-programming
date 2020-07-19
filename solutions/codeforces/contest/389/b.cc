/*
ID: zhaowei10
TASK:
LANG: C++14
*/
#include "bits/stdc++.h"

using namespace std;

#ifdef LOCAL
#include "../../_library/cc/debug.h"
#define FILE "test"
#else
#define debug(...) 0
#define FILE ""
#endif

bool ok(vector<vector<char>>& grid, int r, int c) {
  return r >= 0 && c >= 0 && r < grid.size() && c < grid[0].size() &&
         grid[r][c] == '#';
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int n;
  cin >> n;
  vector<vector<char>> grid(n, vector<char>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> grid[i][j];
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (grid[i][j] == '#') {
        if (ok(grid, i + 1, j) && ok(grid, i + 1, j - 1) &&
            ok(grid, i + 1, j + 1) && ok(grid, i + 2, j)) {
          grid[i + 1][j] = 0;
          grid[i + 1][j - 1] = 0;
          grid[i + 1][j + 1] = 0;
          grid[i + 2][j] = 0;
          grid[i][j] = 0;
        } else {
          cout << "NO";
          return 0;
        }
      }
    }
  }
  cout << "YES";
}
