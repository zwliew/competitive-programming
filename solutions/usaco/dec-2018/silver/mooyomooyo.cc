#include <algorithm>
#include <array>
#include <bitset>
#include <chrono>
#include <climits>
#include <cmath>
#include <deque>
#include <ext/pb_ds/assoc_container.hpp>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
//#include "bits/stdc++.h"

using namespace std;

#ifdef LOCAL
#include "../../_library/cc/debug.h"
#define FILE "test"
#else
#define debug(...) 0
#define FILE "mooyomooyo"
#endif

vector<vector<char>> grid;
vector<vector<bool>> vis;
vector<pair<int, int>> curVis;
int n;

void dfs(int r, int c, char x) {
  if (r < 0 || c < 0 || r >= n || c >= 10)
    return;
  if (vis[r][c] || x != grid[r][c])
    return;
  curVis.emplace_back(r, c);
  vis[r][c] = true;
  dfs(r - 1, c, x);
  dfs(r + 1, c, x);
  dfs(r, c - 1, x);
  dfs(r, c + 1, x);
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  // Simulate the process while there are still >=k-sized components.
  int k;
  cin >> n >> k;

  grid.assign(n, vector<char>(10));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 10; ++j) {
      cin >> grid[i][j];
    }
  }

  bool changed = true;
  while (changed) {
    changed = false;

    vis.assign(n, vector<bool>(10));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < 10; ++j) {
        if (!vis[i][j] && grid[i][j] != '0') {
          curVis.clear();
          dfs(i, j, grid[i][j]);
          if (curVis.size() >= k) {
            changed = true;
            for (auto& p : curVis) {
              grid[p.first][p.second] = '0';
            }
          }
        }
      }
    }

    for (int c = 0; c < 10; ++c) {
      for (int r = n - 1, i = n - 1; r >= 0; --r) {
        while (i >= 0 && grid[i][c] == '0')
          --i;
        if (i >= 0) {
          grid[r][c] = grid[i][c];
        } else {
          grid[r][c] = '0';
        }
        --i;
      }
    }
  }

  for (int r = 0; r < n; ++r) {
    for (int c = 0; c < 10; ++c) {
      cout << grid[r][c];
    }
    cout << '\n';
  }
}
