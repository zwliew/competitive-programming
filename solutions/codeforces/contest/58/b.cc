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

  int n;
  cin >> n;
  vector<int> factors = {1};
  int tmp = n;
  for (int64_t i = 2; i * i <= tmp; ++i) {
    if (tmp % i == 0) {
      while (tmp % i == 0) {
        tmp /= i;
        factors.emplace_back(i);
      }
    }
  }
  if (tmp > 1) {
    factors.emplace_back(tmp);
  }

  for (int i = 0; i < factors.size(); ++i) {
    n /= factors[i];
    cout << n << ' ';
  }
