#include <bits/stdc++.h>
using namespace std;
#define debug(...) 0
#ifdef LOCAL
#include "../../_library/cc/debug.h"
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
#if defined(FILE) && !defined(LOCAL)
  freopen(FILE ".in", "r", stdin), freopen(FILE ".out", "w", stdout);
#endif

  int T;
  cin >> T;
  while (T--) {
    int Q, D;
    cin >> Q >> D;
    vector<bool> dp(D * 10);
    dp[0] = true;
    for (int i = 1; i < D * 10; ++i) {
      for (int j = 0; j < i; ++j) {
        if (dp[j]) {
          int delta = i - j;
          bool hasD = false;
          while (delta) {
            if (delta % 10 == D) {
              hasD = true;
              break;
            }
            delta /= 10;
          }
          if (hasD) {
            dp[i] = true;
            break;
          }
        }
      }
    }

    while (Q--) {
      int A;
      cin >> A;
      cout << (A >= D * 10 || dp[A] ? "yes\n" : "no\n");
    }
  }
}
