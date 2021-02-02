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

  int N, M;
  cin >> N >> M;
  vector<vector<bool>> grid(N, vector<bool>(M));
  queue<array<int, 2>> monsterQ, q;
  vector<vector<int>> monsterDist(N, vector<int>(M, INT_MAX)),
      dist(N, vector<int>(M, INT_MAX));
  vector<array<int, 2>> ends;
  for (int r = 0; r < N; ++r) {
    for (int c = 0; c < M; ++c) {
      char x;
      cin >> x;
      if (x != '#') {
        grid[r][c] = true;
        if (r == N - 1 || !r || !c || c == M - 1) {
          ends.push_back({r, c});
        }
      }
      if (x == 'M') {
        monsterQ.push({r, c});
        monsterDist[r][c] = 0;
      } else if (x == 'A') {
        q.push({r, c});
        dist[r][c] = 0;
      }
    }
  }

  const vector<array<int, 2>> edges = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
  const string edgeNames = "UDRL";
  vector<vector<int>> p(N, vector<int>(M, -1));
  auto bfs = [&](queue<array<int, 2>>& q, vector<vector<int>>& d, bool me) {
    while (q.size()) {
      auto u = q.front();
      q.pop();
      for (int i = 0; i < 4; ++i) {
        int r = u[0] + edges[i][0];
        int c = u[1] + edges[i][1];
        if (r < 0 || c < 0 || r >= N || c >= M || !grid[r][c] ||
            d[r][c] != INT_MAX)
          continue;
        if (me && monsterDist[r][c] <= d[u[0]][u[1]] + 1)
          continue;
        q.push({r, c});
        d[r][c] = d[u[0]][u[1]] + 1;
        if (me)
          p[r][c] = i;
      }
    }
  };
  bfs(monsterQ, monsterDist, false);
  bfs(q, dist, true);

  array<int, 2> end = {-1, -1};
  for (auto& [r, c] : ends) {
    if (dist[r][c] != INT_MAX) {
      end = {r, c};
      break;
    }
  }

  if (end[0] == -1) {
    cout << "NO";
  } else {
    cout << "YES\n" << dist[end[0]][end[1]] << "\n";
    int r = end[0];
    int c = end[1];
    string ans;
    while (p[r][c] != -1) {
      ans += edgeNames[p[r][c]];
      int tmp = r;
      r -= edges[p[r][c]][0];
      c -= edges[p[tmp][c]][1];
    }
    reverse(ans.begin(), ans.end());
    cout << ans;
  }
}
