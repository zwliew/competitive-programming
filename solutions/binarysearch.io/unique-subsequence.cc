#include <bits/stdc++.h>

#include "solution.hpp"
using namespace std;

int Solution::solve(string s, string t) {
  const int mod = 1e9 + 7;
  vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1));
  for (int i = 0; i <= s.size(); ++i) {
    dp[i][0] = 1;
  }
  for (int i = 1; i <= s.size(); ++i) {
    for (int j = 1; j <= t.size(); ++j) {
      dp[i][j] = dp[i - 1][j];
      if (s[i - 1] == t[j - 1]) {
        dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % mod;
      }
    }
  }
  return dp[s.size()][t.size()];
};
