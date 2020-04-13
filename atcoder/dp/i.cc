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
  vector<ld> p(n);
  for (int i = 0; i < n; ++i) cin >> p[i];
  vector<vector<ld>> dp(n + 1, vector<ld>(n + 1));
  dp[0][0] = 1;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= n; ++j) {
      dp[i][j] = dp[i - 1][j] * (1 - p[i - 1]);
      if (j) {
        dp[i][j] += dp[i - 1][j - 1] * p[i - 1];
      }
    }
  }
  ld sum = 0;
  for (int i = (n + 1) / 2; i <= n; ++i) {
    sum += dp[n][i];
  }
  cout << fixed << setprecision(10) << sum;
}
