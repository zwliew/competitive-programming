#include <bits/stdc++.h>
using namespace std;
#define debug(...) 0
#ifdef LOCAL
#include "../../_library/cc/debug.h"
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
#if defined(FILE) && !defined(LOCAL)
  freopen(FILE ".in", "r", stdin), freopen(FILE ".out", "w", stdout);
#endif

  vector<vector<char>> grid(9, vector<char>(9));
  for (int i = 1; i < 8; ++i) {
    for (int j = 1; j < 8; ++j) {
      if ((i <= 2 || i >= 6) && (j <= 2 || j >= 6))
        continue;
      cin >> grid[i][j];
    }
  }

  auto check = [&](int r1, int c1, int r2, int c2) {
    return grid[r1][c1] == 'o' && grid[r2][c2] == '.';
  };

  int cnt = 0;
  for (int i = 1; i < 8; ++i) {
    for (int j = 1; j < 8; ++j) {
      if (grid[i][j] != 'o')
        continue;
      cnt += check(i + 1, j, i + 2, j);
      cnt += check(i - 1, j, i - 2, j);
      cnt += check(i, j + 1, i, j + 2);
      cnt += check(i, j - 1, i, j - 2);
    }
  }
  cout << cnt;
}
