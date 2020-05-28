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

  // 0-1 BFS.
  int h, w;
  cin >> h >> w;
  vector<vector<char>> grid(h, vector<char>(w));
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      cin >> grid[i][j];
      grid[i][j] -= '0';
    }
  }

  const vector<tuple<int, int, char>> edges = {
      {-1, 0, 0}, {-1, 1, 1}, {0, 1, 2},  {1, 1, 3},
      {1, 0, 4},  {1, -1, 5}, {0, -1, 6}, {-1, -1, 7},
  };
  int n;
  cin >> n;
  while (n--) {
    int sr, sc, gr, gc;
    cin >> sr >> sc >> gr >> gc;
    --sr, --sc, --gr, --gc;

    vector<vector<ii>> p(h, vector<ii>(w));
    vector<vi> dist(h, vi(w, 1e9));
    dist[sr][sc] = 0;
    deque<ii> q;
    q.emplace_front(sr, sc);
    while (q.size()) {
      auto [r, c] = q.front();
      q.pop_front();

      if (r == gr && c == gc) {
        cout << dist[r][c] << '\n';
        break;
      }

      for (auto &[dr, dc, dd] : edges) {
        int nr = r + dr;
        int nc = c + dc;
        int ndist = dist[r][c] + (dd != grid[r][c]);
        if (nr < 0 || nc < 0 || nr >= h || nc >= w) continue;
        if (ndist >= dist[nr][nc]) continue;
        dist[nr][nc] = ndist;
        p[nr][nc] = {r, c};
        if (dd != grid[r][c]) {
          q.emplace_back(nr, nc);
        } else {
          q.emplace_front(nr, nc);
        }
      }
    }
  }
}
