#include <bits/stdc++.h>
using namespace std;
#define debug(...) 0
#ifdef LOCAL
#include "../../_library/cc/debug.h"
#endif
// #define FILE

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
#if defined(FILE) && !defined(LOCAL)
  freopen(FILE ".in", "r", stdin), freopen(FILE ".out", "w", stdout);
#endif

  int N;
  cin >> N;
  while (N--) {
    int M;
    cin >> M;
    vector<vector<int>> dp(M + 1, vector<int>(1001, 1e9));
    vector<int> V(M);
    dp[0][0] = 0;
    for (int i = 1; i <= M; ++i) {
      cin >> V[i - 1];
      for (int j = 0; j <= 1000; ++j) {
        if (j >= V[i - 1]) {
          dp[i][j] = min(dp[i][j], max(dp[i - 1][j - V[i - 1]], j));
        }
        if (j + V[i - 1] <= 1000) {
          dp[i][j] = min(dp[i][j], dp[i - 1][j + V[i - 1]]);
        }
      }
    }

    if (dp[M][0] == 1e9) {
      cout << "IMPOSSIBLE\n";
      continue;
    }

    int j = 0;
    string ans;
    for (int i = M; i; --i) {
      if (j >= V[i - 1] && dp[i][j] == max(dp[i - 1][j - V[i - 1]], j)) {
        ans += 'U';
        j -= V[i - 1];
      } else {
        ans += 'D';
        j += V[i - 1];
      }
    }
    reverse(ans.begin(), ans.end());
    cout << ans << '\n';
  }
}
