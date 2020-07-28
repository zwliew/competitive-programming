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

  int64_t n;
  while (cin >> n && n) {
    cout << n << " = ";
    bool first = true;
    if (n < 0) {
      n = -n;
      cout << "-1";
      first = false;
    }

    for (int64_t i = 2; i * i <= n; ++i) {
      if (n % i == 0) {
        while (n % i == 0) {
          if (!first) {
            cout << " x ";
          } else {
            first = false;
          }
          cout << i;
          n /= i;
        }
      }
    }

    if (n > 1) {
      if (!first) {
        cout << " x ";
      }
      cout << n;
    }
    cout << '\n';
  }
}
