#include <bits/stdc++.h>
using namespace std;
#define debug(...) 0
#ifdef LOCAL
#include "../../_library/cc/debug.h"
#endif

bool inBound(int N, int r, int c) {
  return r >= 0 && r < N && c >= 0 && c < N;
}

const vector<array<int, 2>> edges = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

int dfs(vector<vector<int>>& grid,
        vector<vector<bool>>& orig,
        vector<vector<bool>>& vis,
        int r,
        int c,
        int col) {
  vis[r][c] = true;
  int cnt = 1;
  for (auto& [dr, dc] : edges) {
    int nr = r + dr;
    int nc = c + dc;
    if (inBound(grid.size(), nr, nc) && !vis[nr][nc] &&
        (grid[nr][nc] == col || orig[nr][nc])) {
      cnt += dfs(grid, orig, vis, nr, nc, col);
    }
  }
  return cnt;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
#if defined(FILE) && !defined(LOCAL)
  freopen(FILE ".in", "r", stdin), freopen(FILE ".out", "w", stdout);
#endif

  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    vector<vector<int>> grid(N, vector<int>(N));
    bool homogeneous = true;
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        char c;
        cin >> c;
        c -= '0';
        grid[i][j] = c;
        homogeneous = homogeneous && grid[i][j] == grid[0][0];
      }
    }

    vector<vector<bool>> nxtConnected(N, vector<bool>(N));
    vector<vector<bool>> connected(N, vector<bool>(N));
    int cnt = dfs(grid, nxtConnected /* unused */, connected, 0, 0, grid[0][0]);

    vector<int> chosen(6);
    int total = 0;
    while (cnt < N * N) {
      int bestColor = 0;
      int bestCnt = 0;
      nxtConnected = vector<vector<bool>>(N, vector<bool>(N));
      for (int col = 1; col <= 6; ++col) {
        vector<vector<bool>> curConnected(N, vector<bool>(N));
        int curCnt = dfs(grid, connected, curConnected, 0, 0, col);
        if (curCnt > bestCnt) {
          swap(nxtConnected, curConnected);
          bestColor = col;
          bestCnt = curCnt;
        }
      }
      assert(bestColor >= 1);
      ++chosen[bestColor - 1];
      ++total;
      swap(connected, nxtConnected);
      cnt = bestCnt;
    }

    cout << total << "\n";
    for (int x : chosen) {
      cout << x << " ";
    }
    cout << "\n";
  }
}
