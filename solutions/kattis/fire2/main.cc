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

  // MSSP for fire sources, then SSSP for person.
  int t;
  cin >> t;
  while (t--) {
    int w, h;
    cin >> w >> h;
    vector<vb> grid(h, vb(w));
    ii start;
    queue<ii> q;
    vector<vi> dist(h, vi(w, 1e9));
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        char c;
        cin >> c;
        if (c == '@') {
          start = {i, j};
        } else if (c == '*') {
          q.emplace(i, j);
          dist[i][j] = 0;
        }
        grid[i][j] = c != '#';
      }
    }

    while (q.size()) {
      auto u = q.front();
      q.pop();
      auto [r, c] = u;
      int ndist = dist[r][c] + 1;
      for (int d : {-1, 1}) {
        int nr = r + d;
        ii p = {nr, c};
        if (nr >= 0 && nr < h && grid[nr][c] && ndist < dist[nr][c]) {
          dist[nr][c] = ndist;
          q.emplace(p);
        }

        int nc = u.second + d;
        p = {r, nc};
        if (nc >= 0 && nc < w && grid[r][nc] && ndist < dist[r][nc]) {
          dist[r][nc] = ndist;
          q.emplace(p);
        }
      }
    }

    vector<vi> mdist(h, vi(w, 1e9));
    q.emplace(start);
    mdist[start.first][start.second] = 0;
    bool found = 0;
    while (q.size()) {
      auto u = q.front();
      q.pop();
      auto [r, c] = u;
      int ndist = mdist[r][c] + 1;
      if (!r || !c || r == h - 1 || c == w - 1) {
        cout << ndist << '\n';
        found = 1;
        break;
      }

      for (int d : {-1, 1}) {
        int nr = r + d;
        ii p = {nr, c};
        if (nr >= 0 && nr < h && grid[nr][c] && ndist < mdist[nr][c] &&
            ndist < dist[nr][c]) {
          mdist[nr][c] = ndist;
          q.emplace(p);
        }

        int nc = c + d;
        p = {r, nc};
        if (nc >= 0 && nc < w && grid[r][nc] && ndist < mdist[r][nc] &&
            ndist < dist[r][nc]) {
          mdist[r][nc] = ndist;
          q.emplace(p);
        }
      }
    }

    if (!found) cout << "IMPOSSIBLE\n";
  }
}
