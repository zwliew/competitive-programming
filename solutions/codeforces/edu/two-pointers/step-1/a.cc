#include <bits/stdc++.h>
using namespace std;
#define debug(...) 0
#ifdef LOCAL
#include "../../_library/cc/debug.h"
#endif
// #define FILE "milkvisits"

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
#if defined(FILE) && !defined(LOCAL)
  freopen(FILE ".in", "r", stdin), freopen(FILE ".out", "w", stdout);
#endif

  array<int, 2> SZ;
  cin >> SZ[0] >> SZ[1];
  vector<vector<int>> V(2);
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < SZ[i]; ++j) {
      int x;
      cin >> x;
      V[i].push_back(x);
    }
  }

  for (int i = 0, j = 0; i < SZ[0] || j < SZ[1];) {
    if (j == SZ[1] || (i < SZ[0] && V[0][i] < V[1][j])) {
      cout << V[0][i];
      ++i;
    } else {
      cout << V[1][j];
      ++j;
    }
    cout << " ";
  }
}
