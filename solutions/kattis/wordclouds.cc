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

  int N, C;
  cin >> N >> C;
  vector<array<int, 2>> V(N);
  for (auto& x : V)
    cin >> x[0] >> x[1];

  vector<int> dp(N + 1, INT_MAX);
  dp[0] = 0;
  for (int i = 1; i <= N; ++i) {
    for (int j = i, w = 0, h = 0; j && w + V[j - 1][0] <= C; --j) {
      w += V[j - 1][0];
      h = max(h, V[j - 1][1]);
      dp[i] = min(dp[i], dp[j - 1] + h);
    }
  }
  cout << dp[N];
}
