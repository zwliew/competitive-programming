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

  long double c;
  cin >> c;

  long double lo = 0, hi = 1e9;
  for (int i = 0; i < 100; ++i) {
    auto m = lo + (hi - lo) / 2;
    if (m * m + sqrtl(m) <= c) {
      lo = m;
    } else {
      hi = m;
    }
  }
  cout << fixed << setprecision(6) << lo;
}
