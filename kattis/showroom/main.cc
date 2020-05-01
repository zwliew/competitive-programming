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
using vc = vector<char>;
using vb = vector<bool>;
using ii = pair<int, int>;

#define eb emplace_back

int main() {
  cin.tie(nullptr);

  // 0-1 BFS. Car = 1 cost, door = 0 cost.
  int h, w;
  cin >> h >> w;
  vector<vc> grid(h, vc(w));
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      cin >> grid[i][j];
    }
  }
  int sr, sc;
  cin >> sr >> sc;
  deque<ii> q;
  vector<vi> dist(h, vi(w, 1e9));
  q.emplace_front(sr - 1, sc - 1);
  dist[sr - 1][sc - 1] = 0;
  while (q.size()) {
    auto [r, c] = q.front();
    q.pop_front();

    if (!r || !c || r == h - 1 || c == w - 1) {
      cout << dist[r][c];
      return 0;
    }

    int ndist = dist[r][c] + (grid[r][c] == 'c');

    for (int d = -1; d <= 1; ++d) {
      int nr = r + d;
      if (nr >= 0 && nr < h && grid[nr][c] != '#' && ndist < dist[nr][c]) {
        dist[nr][c] = ndist;
        if (grid[r][c] == 'c') {
          q.emplace_back(nr, c);
        } else {
          q.emplace_front(nr, c);
        }
      }
      int nc = c + d;
      if (nc >= 0 && nc < w && grid[r][nc] != '#' && ndist < dist[r][nc]) {
        dist[r][nc] = ndist;
        if (grid[r][c] == 'c') {
          q.emplace_back(r, nc);
        } else {
          q.emplace_front(r, nc);
        }
      }
    }
  }
}
