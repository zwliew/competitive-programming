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
using vb = vector<bool>;
using ii = pair<int, int>;

#define eb emplace_back

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  // Multi-source shortest paths on a grid.
  int r, c, n;
  cin >> r >> c >> n;

  queue<ii> q;
  vector<vi> dist(r, vi(c, 1e9));
  for (int i = 0; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    --x;
    --y;
    dist[x][y] = 1;
    q.emplace(x, y);
  }

  const vector<ii> edges = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
  int ans = 1;
  while (q.size()) {
    auto [x, y] = q.front();
    q.pop();
    for (auto &[dx, dy] : edges) {
      int nx = dx + x;
      int ny = dy + y;
      if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
      int ndist = dist[x][y] + 1;
      if (ndist >= dist[nx][ny]) continue;
      dist[nx][ny] = ndist;
      ans = max(ans, ndist);
      q.emplace(nx, ny);
    }
  }

  cout << ans;
}
