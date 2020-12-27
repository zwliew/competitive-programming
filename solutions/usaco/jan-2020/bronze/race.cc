#include <bits/stdc++.h>
using namespace std;
#define debug(...) 0
#ifdef LOCAL
#include "../../_library/cc/debug.h"
#endif
#define FILE "race"

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
#if defined(FILE) && !defined(LOCAL)
  freopen(FILE ".in", "r", stdin), freopen(FILE ".out", "w", stdout);
#endif

  int K, N;
  cin >> K >> N;
  for (int i = 0; i < N; ++i) {
    int X;
    cin >> X;
    int lhs = 0, rhs = 0, t = 0;
    for (int spd = 1;; ++spd) {
      lhs += spd;
      ++t;
      if (lhs + rhs >= K) {
        break;
      }
      if (spd >= X) {
        rhs += spd;
        ++t;
        if (lhs + rhs >= K) {
          break;
        }
      }
    }
    cout << t << '\n';
  }
}
