#include <bits/stdc++.h>
using namespace std;
#define debug(...) 0
#ifdef LOCAL
#include "../../_library/cc/debug.h"
#endif
// #define FILE "milkvisits"

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
#if defined(FILE) && !defined(LOCAL)
  freopen(FILE ".in", "r", stdin), freopen(FILE ".out", "w", stdout);
#endif

  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    int prev = 0;
    int ans = 0;
    while (N--) {
      int X;
      cin >> X;
      if (X == prev) {
        ++X;
      }
      if (X > prev) {
        ++ans;
        prev = X;
      }
    }
    cout << ans << "\n";
  }
}
