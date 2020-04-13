#include <stdio.h>

#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <deque>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

using ll = long long;
using ld = long double;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  vector<vector<int>> x(3, vector<int>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 3; ++j) {
      cin >> x[j][i];
    }
  }
  vector<vector<int>> dp(n + 1, vector<int>(3));
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < 3; ++j) {
      for (int k = 0; k < 3; ++k) {
        if (j == k) continue;
        dp[i][j] = max(dp[i][j], dp[i - 1][k] + x[j][i - 1]);
      }
    }
  }
  cout << *max_element(dp[n].begin(), dp[n].end());
}
