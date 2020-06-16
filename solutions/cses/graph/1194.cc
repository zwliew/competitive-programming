/*
ID: zhaowei10
TASK:
LANG: C++14
*/
#include "bits/extc++.h"

using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;

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

  int n, m;
  cin >> n >> m;
  vector<vector<char>> grid(n, vector<char>(m));
  queue<pair<int, int>> q, mq;
  vector<vector<int>> dist(n, vector<int>(m, INT_MAX)),
      mdist(n, vector<int>(m, INT_MAX));
  vector<vector<int>> p(n, vector<int>(m, -1));
  pair<int, int> start;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> grid[i][j];
      if (grid[i][j] == 'A') {
        q.emplace(i, j);
        dist[i][j] = 0;
        start = {i, j};
      } else if (grid[i][j] == 'M') {
        mq.emplace(i, j);
        mdist[i][j] = 0;
      }
    }
  }

  vector<char> dirs = {'R', 'L', 'U', 'D'};
  vector<pair<int, int>> deltas = {
      {0, 1},
      {0, -1},
      {-1, 0},
      {1, 0},
  };

  while (mq.size()) {
    auto [r, c] = mq.front();
    mq.pop();

    int nd = mdist[r][c] + 1;
    for (auto &[dr, dc] : deltas) {
      int nr = r + dr;
      int nc = c + dc;
      if (nr < 0 || nc < 0 || nr >= n || nc >= m || grid[nr][nc] == '#')
        continue;
      if (mdist[nr][nc] <= nd) continue;

      mdist[nr][nc] = nd;
      mq.emplace(nr, nc);
    }
  }

  while (q.size()) {
    auto [r, c] = q.front();
    q.pop();

    debug(r, c);

    if (r == n - 1 || !r || !c || c == m - 1) {
      cout << "YES\n";
      cout << dist[r][c] << '\n';
      string ans;
      while (r != start.first || c != start.second) {
        int dir = p[r][c];
        ans += dirs[dir];
        r -= deltas[dir].first;
        c -= deltas[dir].second;
      }
      reverse(ans.begin(), ans.end());
      cout << ans;
      return 0;
    }

    int nd = dist[r][c] + 1;
    for (int i = 0; i < 4; ++i) {
      auto &[dr, dc] = deltas[i];
      int nr = r + dr;
      int nc = c + dc;
      if (nr < 0 || nc < 0 || nr >= n || nc >= m) continue;
      if (grid[nr][nc] == '#' || grid[nr][nc] == 'M') continue;
      if (dist[nr][nc] <= nd) continue;
      if (mdist[nr][nc] <= nd) continue;

      dist[nr][nc] = nd;
      p[nr][nc] = i;
      q.emplace(nr, nc);
    }
  }

  cout << "NO";
}
