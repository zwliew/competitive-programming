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

  // MSSP for each fire source, then SSSP for Joe.
  int h, w;
  cin >> h >> w;
  vector<vb> grid(h, vb(w));
  int sr, sc;
  queue<ii> q;
  vector<vi> fdist(h, vi(w, 1e9));
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      char c;
      cin >> c;
      grid[i][j] = c != '#';
      if (c == 'J') {
        sr = i;
        sc = j;
      } else if (c == 'F') {
        q.emplace(i, j);
        fdist[i][j] = 0;
      }
    }
  }

  while (q.size()) {
    auto [r, c] = q.front();
    q.pop();
    int ndist = fdist[r][c] + 1;
    for (int d : {-1, 1}) {
      int nr = r + d;
      int nc = c + d;

      if (nr >= 0 && nr < h && grid[nr][c] && ndist < fdist[nr][c]) {
        q.emplace(nr, c);
        fdist[nr][c] = ndist;
      }

      if (nc >= 0 && nc < w && grid[r][nc] && ndist < fdist[r][nc]) {
        q.emplace(r, nc);
        fdist[r][nc] = ndist;
      }
    }
  }

  vector<vi> jdist(h, vi(w, 1e9));
  jdist[sr][sc] = 0;
  q.emplace(sr, sc);
  bool escaped = 0;
  while (q.size()) {
    auto [r, c] = q.front();
    q.pop();
    int ndist = jdist[r][c] + 1;

    if (!r || !c || c == w - 1 || r == h - 1) {
      escaped = 1;
      cout << ndist;
      break;
    }

    for (int d : {-1, 1}) {
      int nr = r + d;
      int nc = c + d;

      if (nr >= 0 && nr < h && grid[nr][c] && ndist < jdist[nr][c] &&
          ndist < fdist[nr][c]) {
        q.emplace(nr, c);
        jdist[nr][c] = ndist;
      }

      if (nc >= 0 && nc < w && grid[r][nc] && ndist < jdist[r][nc] &&
          ndist < fdist[r][nc]) {
        q.emplace(r, nc);
        jdist[r][nc] = ndist;
      }
    }
  }

  if (!escaped) cout << "IMPOSSIBLE";
}
