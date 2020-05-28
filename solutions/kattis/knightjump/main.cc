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

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  // SSSP on unweighted graph.
  int n;
  cin >> n;
  vector<vector<char>> grid(n, vector<char>(n));
  queue<tuple<int, int, int>> q;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> grid[i][j];
      if (grid[i][j] == 'K') {
        q.emplace(i, j, 0);
      }
    }
  }

  set<pair<int, int>> vis;
  while (q.size()) {
    auto [x, y, w] = q.front();
    if (x == 0 && y == 0) {
      cout << w;
      return 0;
    }
    q.pop();
    for (int dx = -2; dx <= 2; ++dx) {
      for (int dy = -2; dy <= 2; ++dy) {
        if (dx == dy || dx == -dy || !dx || !dy) continue;
        if (x + dx < 0 || x + dx >= n || y + dy < 0 || y + dy >= n) continue;
        if (grid[x + dx][y + dy] == '#') continue;
        auto p = make_pair(x + dx, y + dy);
        if (!vis.count(p)) {
          vis.emplace(p);
          q.emplace(x + dx, y + dy, w + 1);
        }
      }
    }
  }

  cout << -1;
}
