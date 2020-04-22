#include <bits/stdc++.h>

#include "solution.hpp"
using namespace std;

int Solution::solve(string s0, string s1) {
  vector<vector<int>> dp(s0.size() + 1, vector<int>(s1.size() + 1, 1e9));
  dp[0][0] = 0;
  for (int i = 1; i <= s0.size(); ++i) {
    dp[i][0] = i;
  }
  for (int i = 1; i <= s1.size(); ++i) {
    dp[0][i] = i;
  }
  for (int i = 1; i <= s0.size(); ++i) {
    for (int j = 1; j <= s1.size(); ++j) {
      if (s0[i - 1] == s1[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1];
      } else {
        dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
      }
    }
  }
  return dp[s0.size()][s1.size()];
};
