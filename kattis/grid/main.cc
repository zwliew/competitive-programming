#include <stdio.h>

#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

using ll = long long;
using ld = long double;
using vi = vector<int>;
using ii = pair<int, int>;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  // SSSP with a single destination on a grid
  // Simple BFS while keeping track of distances
  int n, m;
  cin >> n >> m;
  vector<vi> grid(n, vi(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      char c;
      cin >> c;
      grid[i][j] = c - '0';
    }
  }

  vector<ii> edges = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
  vector<vi> dist(n, vi(m, 1e9));
  queue<ii> q;
  q.emplace(0, 0);
  dist[0][0] = 0;
  while (q.size()) {
    auto [r, c] = q.front();
    q.pop();
    if (r == n - 1 && c == m - 1) {
      cout << dist[r][c];
      return 0;
    }

    for (auto &[dr, dc] : edges) {
      int nr = r + dr * grid[r][c];
      int nc = c + dc * grid[r][c];
      if (nr < 0 || nc < 0 || nr >= n || nc >= m) continue;
      int ndist = dist[r][c] + 1;
      if (ndist >= dist[nr][nc]) continue;
      dist[nr][nc] = ndist;
      q.emplace(nr, nc);
    }
  }

  cout << -1;
}
