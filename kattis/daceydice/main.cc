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

const int top = 0, btm = 1, lft = 2, rgt = 3, up = 4, down = 5;
const vector<pair<int, int>> deltas = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const vector<vector<int>> fives = {
    {down, up, lft, rgt, top, btm},
    {rgt, lft, top, btm, up, down},
    {up, down, lft, rgt, btm, top},
    {lft, rgt, btm, top, up, down},
};  // fives[direction in deltas][current five pos]

bool reachable(set<tuple<int, int, int>> &visited, vector<vector<bool>> &grid,
               int vr, int vc, int ur, int uc, int pos) {
  if (ur == vr && uc == vc && pos == btm) return 1;

  for (int i = 0; i < deltas.size(); ++i) {
    auto &[dr, dc] = deltas[i];
    int r = ur + dr;
    int c = uc + dc;
    if (r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size()) continue;
    if (!grid[r][c]) continue;
    auto tup = make_tuple(r, c, fives[i][pos]);
    if (visited.count(tup)) continue;
    visited.emplace(tup);
    if (reachable(visited, grid, vr, vc, r, c, fives[i][pos])) {
      return 1;
    }
  }

  return 0;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  // DFS with 3 params
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<vector<bool>> grid(n, vector<bool>(n));
    int vr, vc, ur, uc;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        char c;
        cin >> c;
        if (c == 'S') {
          ur = i;
          uc = j;
        } else if (c == 'H') {
          vr = i;
          vc = j;
        }
        grid[i][j] = c != '*';
      }
    }

    set<tuple<int, int, int>> visited = {{ur, uc, lft}};
    cout << (reachable(visited, grid, vr, vc, ur, uc, lft) ? "Yes" : "No")
         << '\n';
  }
}
