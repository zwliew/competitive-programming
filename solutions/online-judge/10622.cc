/*
ID: zhaowei10
TASK:
LANG: C++14
*/
#include <ext/numeric>
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

  int64_t x;
  while (cin >> x && x) {
    bool neg = false;
    if (x < 0) {
      x = -x;
      neg = true;
    }
    int ans = 0;
    for (int64_t i = 2; i * i <= x; ++i) {
      if (x % i == 0) {
        int cnt = 0;
        while (x % i == 0) {
          x /= i;
          ++cnt;
        }
        ans = __gcd(ans, cnt);
      }
    }
    if (x > 1) {
      ans = 1;
    }

    if (neg) {
      for (int p = ans - !(ans % 2); p >= 1; p -= 2) {
        if (ans % p == 0) {
          ans = p;
          break;
        }
      }
    }
    cout << ans << "\n";
  }
}
