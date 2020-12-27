/*
ID: zhaowei10
LANG: C++14
TASK:
*/
#include <bits/stdc++.h>
using namespace std;
#define debug(...) 0
#ifdef LOCAL
#include "../../_library/cc/debug.h"
#endif
// #define FILE "milk2"

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
#if defined(FILE) && !defined(LOCAL)
  freopen(FILE ".in", "r", stdin), freopen(FILE ".out", "w", stdout);
#endif

  int T;
  cin >> T;
  while (T--) {
    int N;
    array<int, 2> C;
    cin >> N >> C[0] >> C[1];
    array<int64_t, 2> dp;
    int x;
    cin >> x;
    dp[x] = 0;
    dp[!x] = C[x];
    for (int i = 1; i < N; ++i) {
      cin >> x;
      array<int64_t, 2> ndp;
      ndp[x] = dp[!x];
      ndp[!x] = dp[x] + C[x];
      swap(ndp, dp);
    }
    cout << min(dp[0], dp[1]) << "\n";
  }
}
