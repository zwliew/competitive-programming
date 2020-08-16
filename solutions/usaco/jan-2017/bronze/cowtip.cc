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
#define FILE "cowtip"
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int n;
  cin >> n;
  vector<vector<bool>> grid(n, vector<bool>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      char c;
      cin >> c;
      grid[i][j] = c == '1';
    }
  }

  int cnt = 0;
  vector<vector<int>> sufSum(n, vector<int>(n));
  for (int i = n - 1; i >= 0; --i) {
    for (int j = n - 1; j >= 0; --j) {
      sufSum[i][j] = (i < n - 1 ? sufSum[i + 1][j] : 0) +
                     (j < n - 1 ? sufSum[i][j + 1] : 0) -
                     (i < n - 1 && j < n - 1 ? sufSum[i + 1][j + 1] : 0);
      if (grid[i][j] != sufSum[i][j] % 2) {
        sufSum[i][j]++;
        ++cnt;
      }
    }
  }
  cout << cnt;
}
