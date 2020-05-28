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

void dfs(vector<vector<bool>> &grid, int r, int c) {
  const vector<pair<int, int>> edges = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
  for (auto &[dr, dc] : edges) {
    int nr = r + dr;
    int nc = c + dc;
    if (nc < 0 || nr < 0 || nr >= grid.size() || nc >= grid[0].size()) continue;
    if (!grid[nr][nc]) continue;
    grid[nr][nc] = 0;
    dfs(grid, nr, nc);
  }
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  // Count the number of connected components
  int n, m;
  cin >> n >> m;

  vector<vector<bool>> grid(n, vector<bool>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      char c;
      cin >> c;
      grid[i][j] = c == '.';
    }
  }

  int count = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (grid[i][j]) {
        grid[i][j] = 0;
        ++count;
        dfs(grid, i, j);
      }
    }
  }

  cout << count;
}
