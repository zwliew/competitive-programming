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

  ll n, w;
  cin >> n >> w;
  vector<ll> x(n), v(n);
  for (int i = 0; i < n; ++i) {
    cin >> x[i] >> v[i];
  }
  vector<vector<ll>> dp(n + 1, vector<ll>(w + 1));
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= w; ++j) {
      dp[i][j] = dp[i - 1][j];
      if (x[i - 1] <= j) {
        dp[i][j] = max(dp[i][j], dp[i - 1][j - x[i - 1]] + v[i - 1]);
      }
    }
  }
  cout << dp[n][w];
}
