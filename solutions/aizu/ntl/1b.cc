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

int64_t pwr(int64_t b, int64_t e, int64_t m) {
  int64_t res = 1;
  while (e) {
    if (e & 1) {
      res *= b;
      res %= m;
    }
    b *= b;
    b %= m;
    e >>= 1;
  }
  return res;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int64_t m, n;
  cin >> m >> n;
  cout << pwr(m, n, 1e9 + 7) << '\n';
}

