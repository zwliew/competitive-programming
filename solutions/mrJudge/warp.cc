#include <bits/stdc++.h>
using namespace std;
#define debug(...) 0
#ifdef LOCAL
#include "../../_library/cc/debug.h"
#endif
// #define FILE ""

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
#if defined(FILE) && !defined(LOCAL)
  freopen(FILE ".in", "r", stdin), freopen(FILE ".out", "w", stdout);
#endif

  const int M = 1e9 + 7;

  int N;
  cin >> N;

  array<int, 30> dp;
  fill(dp.begin(), dp.end(), 0);

  auto for_each_bit = [](int x, auto&& cb) {
    for (int b = x & -x; x; x -= b, b = x & -x) {
      int i = __builtin_ctz(b);
      cb(i);
    }
  };

  int X;
  cin >> X;
  --N;
  for_each_bit(X, [&](int i) { dp[i] = 1; });

  int cur = 1;
  while (N--) {
    cur = 0;
    int X;
    cin >> X;
    for_each_bit(X, [&](int i) {
      cur += dp[i];
      cur %= M;
    });
    for_each_bit(X, [&](int i) {
      dp[i] += cur;
      dp[i] %= M;
    });
  }
  cout << cur;
}
