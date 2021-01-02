#include <bits/stdc++.h>
using namespace std;
#define debug(...) 0
#ifdef LOCAL
#include "../../_library/cc/debug.h"
#endif
// #define FILE

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
#if defined(FILE) && !defined(LOCAL)
  freopen(FILE ".in", "r", stdin), freopen(FILE ".out", "w", stdout);
#endif

  int R, C;
  cin >> R >> C;
  vector<vector<int>> grid(R, vector<int>(C));
  for (int i = 0; i < R; ++i) {
    for (int j = 0; j < C; ++j) {
      cin >> grid[i][j];
    }
  }

  int r = 0, c = 0;
  int ans = 0;
  while (r != R - 1 || c != C - 1) {
    int br = -1;
    int bc = -1;
    ans += grid[r][c];
    grid[r][c] = 0;
    for (int dr = -1; dr <= 1; ++dr) {
      for (int dc = -1; dc <= 1; ++dc) {
        if ((!dr && !dc) || (dr && dc))
          continue;
        int nr = r + dr;
        int nc = c + dc;
        if (nr < 0 || nr >= R || nc < 0 || nc >= C || !grid[nr][nc])
          continue;
        if (br == -1 || grid[nr][nc] > grid[br][bc]) {
          br = nr;
          bc = nc;
        }
      }
    }
    assert(br != -1);
    r = br;
    c = bc;
  }
  cout << ans + grid[R - 1][C - 1];
}
