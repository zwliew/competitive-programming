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
#define FILE "speeding"
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int n, m;
  cin >> n >> m;
  array<int, 100> lim, spd;
  int curLen = 0;
  for (int i = 0; i < n; ++i) {
    int len, clim;
    cin >> len >> clim;
    while (len--) {
      lim[curLen] = clim;
      curLen++;
    }
  }

  int ans = 0;
  curLen = 0;
  for (int i = 0; i < m; ++i) {
    int len, cspd;
    cin >> len >> cspd;
    while (len--) {
      ans = max(ans, cspd - lim[curLen]);
      curLen++;
    }
  }
  cout << ans;
}
