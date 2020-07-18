/*
ID: zhaowei10
TASK:
LANG: C++14
*/
#include "bits/stdc++.h"

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

  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;

  vector<vector<int>> dp(2, vector<int>(k));
  vector<vector<int>> parent(n + 1, vector<int>(k));

  int prev = 0, cur = 1;
  for (int i = 1; i <= n; ++i, prev ^= 1, cur ^= 1) {
    for (int j = 0; j < k; ++j) {
      dp[cur][j] = INT_MAX;

      for (int l = 0; l < k; ++l) {
        if (j == l)
          continue;
        if (dp[cur][j] > dp[prev][l]) {
          dp[cur][j] = dp[prev][l];
          parent[i][j] = l;
        }
      }
      dp[cur][j] += s[i - 1] != j + 'A';
    }
  }

  cur = 0;
  for (int i = 1; i < k; ++i) {
    if (dp[prev][i] < dp[prev][cur]) {
      cur = i;
    }
  }

  cout << dp[prev][cur] << '\n';

  string ans;
  int idx = n;
  do {
    ans += (char)(cur + 'A');
    cur = parent[idx][cur];
    --idx;
  } while (idx);

  reverse(ans.begin(), ans.end());
  cout << ans;
}
