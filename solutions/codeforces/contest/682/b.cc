/*
ID: zhaowei10
TASK:
LANG: C++14
*/
#include "bits/stdc++.h"

using namespace std;

#ifdef LOCAL
#include "../../_library/cc/debug.h"
#define FILE "test"
#else
#define debug(...) 0
#define FILE ""
#endif

bool ok(vector<vector<char>>& grid, int r, int c) {
  return r >= 0 && c >= 0 && r < grid.size() && c < grid[0].size() &&
         grid[r][c] == '#';
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }
}
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto& x : a)
    cin >> x;
  sort(a.begin(), a.end());

  int mex = 1;
  for (int x : a) {
    if (x >= mex) {
      ++mex;
    }
  }
  cout << mex;
