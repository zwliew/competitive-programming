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

  int n;
  long double p;
  cin >> n >> p;

  long double res = 1;
  while (n) {
    if (n & 1) {
      res = res * (1 - p) + p * (1 - res);
    }
    p *= 2 * (1 - p);
    n >>= 1;
  }
  cout << fixed << setprecision(8) << res;
}
