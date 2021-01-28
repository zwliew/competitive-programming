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

  int L, W;
  cin >> L >> W;
  vector<vector<char>> dp(L + 1, vector<char>(W + 1));
  dp[0][0] = 1;
  for (int i = 1; i <= L; ++i) {
    for (int j = 1; j <= W; ++j) {
      if (dp[i][j])
        continue;
      for (int k = 1; k <= 26 && k <= j; ++k) {
        if (dp[i - 1][j - k]) {
          dp[i][j] = k;
        }
      }
    }
  }

  if (!dp[L][W]) {
    cout << "impossible";
    return 0;
  }

  int w = W;
  string ans;
  for (int i = L; i; --i) {
    ans += dp[i][w] + 'a' - 1;
    w -= dp[i][w];
  }
  reverse(ans.begin(), ans.end());
  cout << ans;
}
