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
#define FILE "paintbarn"
#endif

const int MAXN = 1002;
array<array<int, MAXN>, MAXN> grid;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int n, k;
  cin >> n >> k;

  while (n--) {
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    ++r1, ++c2, ++r2, ++c1;
    grid[r1][c1]++;
    grid[r2][c1]--;
    grid[r1][c2]--;
    grid[r2][c2]++;
  }

  int cnt = 0;
  for (int i = 1; i < MAXN - 1; ++i) {
    for (int j = 1; j < MAXN - 1; ++j) {
      grid[i][j] += grid[i - 1][j] + grid[i][j - 1] - grid[i - 1][j - 1];
      cnt += grid[i][j] == k;
    }
  }

  cout << cnt;
}
