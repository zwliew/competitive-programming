#include <bits/stdc++.h>

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

  int N;
  cin >> N;
  const int MX = 700;
  array<vector<vector<bool>>, 2> dp;
  for (int i = 0; i < 2; ++i) {
    dp[i] = vector<vector<bool>>(MX + 100, vector<bool>(MX + 100));
  }
  dp[0][0][0] = true;
  int cur = 0;
  int total = 0;
  while (N--) {
    int x;
    cin >> x;
    total += x;

    int nxt = cur ^ 1;
    for (int i = 0; i < MX; ++i) {
      for (int j = 0; j < MX; ++j) {
        if (dp[cur][i][j]) {
          dp[nxt][i][j] = true;
          dp[nxt][i + x][j] = true;
          dp[nxt][i][j + x] = true;
        }
      }
    }

    cur = nxt;
  }

  int ans = INT_MAX;
  for (int i = 0; i < MX; ++i) {
    for (int j = 0; j < MX; ++j) {
      if (dp[cur][i][j]) {
        ans = min(ans, max({i, j, total - i - j}));
      }
    }
  }
  cout << ans;
}
