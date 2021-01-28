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

  int N, W;
  cin >> N >> W;
  vector<vector<array<int, 2>>> V(W + 1);
  for (int i = 0; i < W + 1; ++i) {
    int K;
    cin >> K;
    V[i].resize(K);
    for (int k = 0; k < 2; ++k) {
      for (int j = 0; j < K; ++j) {
        cin >> V[i][j][k];
      }
    }
  }

  vector<vector<int>> dp(W + 2, vector<int>(N + 1, INT_MIN));
  vector<vector<int>> p(W + 2, vector<int>(N + 1, INT_MAX));
  dp[0][N] = 0;
  for (int i = 1; i < W + 2; ++i) {
    for (int k = 0; k < V[i - 1].size(); ++k) {
      auto& v = V[i - 1][k];
      for (int j = 0; j <= N; ++j) {
        int sold = min(v[1], j);
        int nxt = dp[i - 1][j] + sold * v[0];
        if (nxt > dp[i][j - sold]) {
          dp[i][j - sold] = nxt;
          p[i][j - sold] = i > 1 ? p[i - 1][j] : v[0];
        } else if (nxt == dp[i][j - sold] && p[i][j - sold] > p[i - 1][j]) {
          p[i][j - sold] = i > 1 ? p[i - 1][j] : v[0];
        }
      }
    }
  }

  int cur = 0;
  for (int i = 1; i <= N; ++i) {
    if (dp[W + 1][i] > dp[W + 1][cur]) {
      cur = i;
    } else if (dp[W + 1][i] == dp[W + 1][cur] && p[W + 1][cur] > p[W + 1][i]) {
      cur = i;
    }
  }
  cout << dp[W + 1][cur] << "\n" << p[W + 1][cur];
}
