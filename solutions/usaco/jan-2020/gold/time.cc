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
#define FILE "time"
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int n, m, c;
  cin >> n >> m >> c;
  vector<int> moonies(n);
  for (int i = 0; i < n; ++i)
    cin >> moonies[i];

  vector<vector<int>> adj(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    --u;
    --v;
    adj[v].push_back(u);
  }

  // t^2 <= 1000t => t^2 - 1000t <= 0 => t(t - 1000) <= 0 => 0 <= t <= 1000
  vector<vector<int>> dp(2, vector<int>(n, -1e9));
  int ans = 0;
  dp[0][0] = 0;
  for (int i = 1; i <= 1000; ++i) {
    for (int j = 0; j < n; ++j) {
      for (int x : adj[j]) {
        dp[1][j] = max(dp[1][j], dp[0][x]);
      }
      dp[1][j] += moonies[j];
    }
    ans = max(ans, dp[1][0] - c * i * i);
    dp[0] = dp[1];
    fill(dp[1].begin(), dp[1].end(), -1e9);
  }
  cout << ans;
}
