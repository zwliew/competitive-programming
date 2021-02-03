#include <bits/stdc++.h>
using namespace std;
#define debug(...) 0
#ifdef LOCAL
#include "../../_library/cc/debug.h"
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
#if defined(FILE) && !defined(LOCAL)
  freopen(FILE ".in", "r", stdin), freopen(FILE ".out", "w", stdout);
#endif

  int N, M;
  cin >> N >> M;
  vector<vector<char>> grid(N, vector<char>(M));
  queue<array<int, 2>> q;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      cin >> grid[i][j];
      if (grid[i][j] == 'V') {
        q.push({i, j});
      }
    }
  }

  auto isAir = [&](int r, int c) {
    return r >= 0 && r < N && c >= 0 && c < M && grid[r][c] == '.';
  };
  auto isStone = [&](int r, int c) {
    return r >= 0 && r < N && c >= 0 && c < M && grid[r][c] == '#';
  };
  while (q.size()) {
    auto [r, c] = q.front();
    q.pop();

    int nr = r + 1;
    int nc = c;
    if (isAir(nr, nc)) {
      grid[nr][nc] = 'V';
      q.push({nr, nc});
    }

    if (isStone(nr, nc)) {
      nr = r;
      for (int dc = -1; dc <= 1; ++dc) {
        if (!dc)
          continue;
        nc = c + dc;
        if (isAir(nr, nc)) {
          grid[nr][nc] = 'V';
          q.push({nr, nc});
        }
      }
    }
  }

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      cout << grid[i][j];
    }
    cout << "\n";
  }
}
