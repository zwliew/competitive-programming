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

  int v1, v2, t, d;
  cin >> v1 >> v2 >> t >> d;

  int ans = 0;
  for (int i = 0; i < t; ++i) {
    ans += min(v1 + d * i, v2 + d * (t - i - 1));
  }
  cout << ans;
}
