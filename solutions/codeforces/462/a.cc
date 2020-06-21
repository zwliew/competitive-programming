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

  int n;
  cin >> n;

  vector<vector<char>> grid(n + 2, vector<char>(n + 2));
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      cin >> grid[i][j];
    }
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      int cur = 0;
      cur += grid[i - 1][j] == 'o';
      cur += grid[i + 1][j] == 'o';
      cur += grid[i][j - 1] == 'o';
      cur += grid[i][j + 1] == 'o';
      if (cur % 2) {
        cout << "NO";
        return 0;
      }
    }
  }

  cout << "YES";
}
