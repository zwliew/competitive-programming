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
#define FILE "balancing"
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int n, x, y;
  cin >> n >> x >> y;

  --n;
  int lo = 0, hi = 1e9;
  while (lo < hi) {
    int m = lo + (hi - lo) / 2;
    if (m / x + m / y >= n) {
      hi = m;
    } else {
      lo = m + 1;
    }
  }
  cout << hi + min(x, y);
}
