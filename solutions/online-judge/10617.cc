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

int64_t compute(string& s, vector<vector<int64_t>>& dp, int i, int j) {
  if (i == j) {
    return 1;
  }
  if (i == j - 1) {
    return (s[i] == s[j]) + 2;
  }

  if (dp[i][j] != -1) {
    return dp[i][j];
  }

  int64_t ans = compute(s, dp, i + 1, j) + compute(s, dp, i, j - 1) -
                compute(s, dp, i + 1, j - 1);
  if (s[i] == s[j]) {
    ans += compute(s, dp, i + 1, j - 1) + 1;
  }
  return dp[i][j] = ans;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    vector<vector<int64_t>> dp(s.size(), vector<int64_t>(s.size(), -1));
    cout << compute(s, dp, 0, s.size() - 1) << '\n';
  }
}
