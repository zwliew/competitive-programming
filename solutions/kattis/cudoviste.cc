/*
ID: zhaowei10
TASK:
LANG: C++14
*/
#include "bits/stdc++.h"

using namespace std;

#ifdef LOCAL
#include "../../_library/cpp/debug.h"
#define FILE "test"
#else
#define debug(...) 0
#define FILE ""
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int h, w;
  cin >> h >> w;
  vector<vector<char>> grid(h, vector<char>(w));
  for (int r = 0; r < h; ++r) {
    for (int c = 0; c < w; ++c) {
      cin >> grid[r][c];
    }
  }

  const vector<pair<int, int>> deltas = {
      {1, 0},
      {0, 0},
      {1, 1},
      {0, 1},
  };
  vector<int> ans(5);
  for (int r = 0; r < h - 1; ++r) {
    for (int c = 0; c < w - 1; ++c) {
      bool ok = true;
      int cnt = 0;
      for (auto &[dr, dc] : deltas) {
        int nr = r + dr;
        int nc = c + dc;
        if (grid[nr][nc] == '#') {
          ok = false;
          break;
        }
        cnt += grid[nr][nc] == 'X';
      }

      if (ok) {
        ans[cnt]++;
      }
    }
  }

  for (auto x : ans) {
    cout << x << '\n';
  }
}
