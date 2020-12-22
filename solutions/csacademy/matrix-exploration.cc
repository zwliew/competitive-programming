#include <bits/stdc++.h>

using namespace std;

int main() {
  int N, M, K;
  cin >> N >> M >> K;
  vector<vector<char>> grid(N, vector<char>(M));
  vector<vector<int>> d(N, vector<int>(M, 1e9));
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      cin >> grid[i][j];
    }
  }
  queue<array<int, 2>> q;
  for (int i = 0; i < K; ++i) {
    int x, y;
    cin >> x >> y;
    --x, --y;
    q.push({x, y});
    d[x][y] = 0;
  }

  int64_t ans = 0;
  while (q.size()) {
    auto u = q.front();
    q.pop();
    for (int dr = -1; dr <= 1; ++dr) {
      for (int dc = -1; dc <= 1; ++dc) {
        if (!dc && !dr)
          continue;
        if (dc && dr)
          continue;
        int nr = u[0] + dr;
        int nc = u[1] + dc;
        if (nr < 0 || nc < 0 || nr >= N || nc >= M)
          continue;
        if (grid[nr][nc] == '#')
          continue;
        if (d[nr][nc] > d[u[0]][u[1]] + 1) {
          d[nr][nc] = d[u[0]][u[1]] + 1;
          ans += d[nr][nc];
          q.push({nr, nc});
        }
      }
    }
  }
  cout << ans;
}
