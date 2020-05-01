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

  int x;
  while (cin >> x && x != -1) {
    int y, t, l, w;
    cin >> y >> t >> l >> w;

    // Multi-source shortest paths (MSSP) on an unweighted graph.
    // This is made slightly more difficult by the limitation of path lengths,
    // and the parsing of obstacles.
    vector<vi> dist(x, vi(y, 1e9));
    queue<ii> q;
    vector<ii> sources;
    for (int i = 0; i < l; ++i) {
      int r, c;
      cin >> r >> c;
      --r, --c;
      q.emplace(r, c);
      dist[r][c] = 1;
    }

    vector<vector<bool>> grid(x, vector<bool>(y, 1));
    for (int i = 0; i < w; ++i) {
      int x1, x2, y1, y2;
      cin >> x1 >> y1 >> x2 >> y2;
      --x1, --x2, --y1, --y2;
      if (x1 > x2) {
        swap(x1, x2);
        swap(y1, y2);
      }
      if (x1 == x2) {
        if (y2 < y1) {
          swap(y1, y2);
        }
        for (int c = y1; c <= y2; ++c) {
          grid[x1][c] = 0;
        }
      } else {
        int grad = (y2 - y1) / (x2 - x1);
        for (int r = x1, c = y1; r <= x2; ++r, c += grad) {
          grid[r][c] = 0;
        }
      }
    }

    const vector<ii> edges = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    while (q.size()) {
      auto [r, c] = q.front();
      q.pop();
      for (auto [dr, dc] : edges) {
        int nr = dr + r;
        int nc = dc + c;
        if (nc < 0 || nr < 0 || nr >= x || nc >= y) continue;
        if (!grid[nr][nc]) continue;
        int ndist = dist[r][c] + 1;
        if (ndist >= dist[nr][nc] || ndist > t) continue;
        dist[nr][nc] = ndist;
        q.emplace(nr, nc);
      }
    }

    int count = 0;
    for (int i = 0; i < x; ++i) {
      for (int j = 0; j < y; ++j) {
        if (dist[i][j] < 1e9) {
          ++count;
        }
      }
    }

    cout << count << '\n';
  }
}
