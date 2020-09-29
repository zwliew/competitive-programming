#include <algorithm>
#include <array>
#include <bitset>
#include <chrono>
#include <climits>
#include <cmath>
#include <cstring>
#include <deque>
#include <ext/pb_ds/assoc_container.hpp>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#ifdef LOCAL
#include "../../_library/cc/debug.h"
#define FILE "test"
#else
#define debug(...) 0
#define FILE "snakes"
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int n, k;
  cin >> n >> k;
  vector<int> snakes(n);
  for (int i = 0; i < n; ++i)
    cin >> snakes[i];

  vector<vector<int>> dp(n + 1, vector<int>(k + 1, 1e9));
  for (int i = 0; i <= k; ++i) {
    dp[0][i] = 0;
  }
  int curMax = 0;
  for (int i = 1; i <= n; ++i) {
    curMax = max(curMax, snakes[i - 1]);
    dp[i][0] = i * curMax;
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= k; ++j) {
      curMax = 0;
      for (int e = i; e >= 1; --e) {
        curMax = max(curMax, snakes[e - 1]);
        dp[i][j] = min(dp[i][j], dp[e - 1][j - 1] + (i - e + 1) * curMax);
      }
    }
  }
  cout << dp[n][k] - accumulate(snakes.begin(), snakes.end(), 0);
}
