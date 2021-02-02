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
  array<int, 2> start, end;
  vector<vector<bool>> grid(N, vector<bool>(M));
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      char c;
      cin >> c;
      if (c != '#') {
        grid[i][j] = true;
      }
      if (c == 'A') {
        start = {i, j};
      } else if (c == 'B') {
        end = {i, j};
      }
    }
  }

  const vector<array<int, 2>> edges = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
  const string edgeNames = "UDRL";

  vector<vector<int>> p(N, vector<int>(M, -1));
  queue<array<int, 2>> q;
  q.push({start[0], start[1]});
  grid[start[0]][start[1]] = false;
  while (q.size()) {
    auto u = q.front();
    q.pop();
    for (int i = 0; i < 4; ++i) {
      int dr = edges[i][0];
      int dc = edges[i][1];
      int r = u[0] + dr;
      int c = u[1] + dc;
      if (r < 0 || r >= N || c < 0 || c >= M || !grid[r][c])
        continue;
      grid[r][c] = false;
      q.push({r, c});
      p[r][c] = i;
    }
  }

  if (grid[end[0]][end[1]]) {
    cout << "NO";
  } else {
    cout << "YES\n";
    int r = end[0];
    int c = end[1];
    string ans;
    do {
      ans += edgeNames[p[r][c]];
      int tmp = r;
      r -= edges[p[r][c]][0];
      c -= edges[p[tmp][c]][1];
    } while (p[r][c] != -1);
    reverse(ans.begin(), ans.end());
    cout << ans.size() << "\n" << ans;
  }
}
