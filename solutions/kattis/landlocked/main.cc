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
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

using ll = long long;
using ld = long double;
using vi = vector<int>;
using vb = vector<bool>;
using ii = pair<int, int>;

#define eb emplace_back

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  // MSSP for each country. Solve with 0-1 BFS as crossing borders has a cost of
  // 1, while not crossing has 0 cost.
  int n, m;
  cin >> n >> m;
  vector<vector<ii>> sources(26);
  vector<vector<char>> grid(n, vector<char>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> grid[i][j];
      if (grid[i][j] != 'W') {
        sources[grid[i][j] - 'A'].eb(i, j);
      }
    }
  }

  for (int i = 0; i < sources.size(); ++i) {
    if (sources[i].empty()) continue;

    vector<vi> dist(n, vi(m, 1e9));
    deque<ii> q;
    for (auto &[r, c] : sources[i]) {
      q.emplace_back(r, c);
      dist[r][c] = 0;
    }

    while (q.size()) {
      auto [r, c] = q.front();
      q.pop_front();

      if (grid[r][c] == 'W') {
        cout << (char)(i + 'A') << ' ' << dist[r][c] - 1 << '\n';
        break;
      }

      for (int dr = -1; dr <= 1; ++dr) {
        for (int dc = -1; dc <= 1; ++dc) {
          int nr = dr + r;
          int nc = dc + c;
          if (nr == r && nc == c) continue;
          if (nr < 0 || nc < 0 || nr >= n || nc >= m) continue;
          int ndist = dist[r][c] + (grid[nr][nc] == grid[r][c] ? 0 : 1);
          if (ndist >= dist[nr][nc]) continue;
          if (grid[nr][nc] != grid[r][c]) {
            q.emplace_back(nr, nc);
          } else {
            q.emplace_front(nr, nc);
          }
          dist[nr][nc] = ndist;
        }
      }
    }
  }
}
