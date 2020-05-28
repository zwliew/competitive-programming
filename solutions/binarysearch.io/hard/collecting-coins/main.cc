#include <bits/stdc++.h>

#include "solution.hpp"
using namespace std;

int Solution::solve(vector<vector<int>>& matrix) {
  vector<vector<int>> dp(matrix.size() + 1, vector<int>(matrix[0].size() + 1));
  for (int i = 1; i <= matrix.size(); ++i) {
    for (int j = 1; j <= matrix[0].size(); ++j) {
      dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + matrix[i - 1][j - 1];
    }
  }
  return dp[matrix.size()][matrix[0].size()];
};
