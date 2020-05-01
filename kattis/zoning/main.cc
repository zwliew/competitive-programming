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
  ios::sync_with_stdio(false);

  // MSSP. Find the max out of all shortest paths from any 3 to each 1. Solve
  // this with multi-source BFS.
  int n;
  cin >> n;
  vector<vc> grid(n, vc(n));
  queue<ii> q;
  vector<vi> dist(n, vi(n, 1e9));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> grid[i][j];
      grid[i][j] -= '0';
      if (grid[i][j] == 3) {
        q.emplace(i, j);
        dist[i][j] = 0;
      }
    }
  }

  int ans = 0;
  while (q.size()) {
    auto [r, c] = q.front();
    q.pop();
    if (grid[r][c] == 1) {
      ans = max(ans, dist[r][c]);
    }
    int ndist = dist[r][c] + 1;
    for (int d = -1; d <= 1; ++d) {
      int nr = r + d;
      if (nr >= 0 && nr < n && ndist < dist[nr][c]) {
        dist[nr][c] = ndist;
        q.emplace(nr, c);
      }
      int nc = c + d;
      if (nc >= 0 && nc < n && ndist < dist[r][nc]) {
        dist[r][nc] = ndist;
        q.emplace(r, nc);
      }
    }
  }

  cout << ans;
}
