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

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int m, n;
  cin >> m >> n;
  vector<vector<int>> times(m, vector<int>(n));
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> times[i][j];
    }
  }

  vector<int> free(n);
  for (int i = 0; i < m; ++i) {
    int cur = 0;
    for (int j = 0; j < n; ++j) {
      cur = max(free[j], cur) + times[i][j];
      free[j] = cur;
    }
    cout << cur << ' ';
  }
