#include <algorithm>
#include <array>
#include <bitset>
#include <chrono>
#include <climits>
#include <cmath>
#include <cstring>
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
#define FILE "perimeter"
#endif

vector<vector<char>> grid;
vector<vector<bool>> vis;
int n, a, p;

inline bool valid(int r, int c) {
  return r >= 0 && c >= 0 && r < n && c < n && grid[r][c] == '#';
}

void dfs(int r, int c) {
  if (!valid(r, c))
    return;
  if (vis[r][c])
    return;
  vis[r][c] = true;
  ++a;
  p +=
      !valid(r + 1, c) + !valid(r - 1, c) + !valid(r, c + 1) + !valid(r, c - 1);
  dfs(r + 1, c);
  dfs(r - 1, c);
  dfs(r, c + 1);
  dfs(r, c - 1);
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  cin >> n;
  grid.assign(n, vector<char>(n));
  vis.assign(n, vector<bool>(n));
  for (int r = 0; r < n; ++r) {
    for (int c = 0; c < n; ++c) {
      cin >> grid[r][c];
    }
  }

  int bp = 0, ba = 0;
  for (int r = 0; r < n; ++r) {
    for (int c = 0; c < n; ++c) {
      if (!vis[r][c]) {
        a = 0;
        p = 0;
        dfs(r, c);
        if (a > ba || (a == ba && p < bp)) {
          ba = a;
          bp = p;
        }
      }
    }
  }

  cout << ba << ' ' << bp;
}
