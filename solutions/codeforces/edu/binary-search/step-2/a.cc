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

  int w, h, n;
  cin >> w >> h >> n;

  int64_t lo = 1, hi = 1e18;
  while (lo < hi) {
    auto m = lo + (hi - lo) / 2;
    if ((__int128)(m / w) * (m / h) >= n) {
      hi = m;
    } else {
      lo = m + 1;
    }
  }
  cout << hi;
}
