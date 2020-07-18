/*
ID: zhaowei10
TASK:
LANG: C++14
*/
#include "bits/stdc++.h"

using namespace std;

#ifdef LOCAL
#include "../../_library/cpp/debug.h"
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

  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<int>> grid(n, vector<int>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> grid[i][j];
    }
  }

  vector<int> rows(n), cols(m);
  iota(rows.begin(), rows.end(), 0);
  iota(cols.begin(), cols.end(), 0);

  while (k--) {
    char s;
    int x, y;
    cin >> s >> x >> y;
    --x, --y;
    if (s == 'c') {
      swap(cols[x], cols[y]);
    } else if (s == 'r') {
      swap(rows[x], rows[y]);
    } else {
      cout << grid[rows[x]][cols[y]] << '\n';
    }
  }
}
