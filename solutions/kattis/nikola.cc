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
// #include "bits/stdc++.h"

using namespace std;

#ifdef LOCAL
#include "../../_library/cc/debug.h"
#define FILE "test"
#else
#define debug(...) 0
#define FILE "cowjog"
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int n;
  cin >> n;
  vector<int> fees(n);
  for (auto& x : fees)
    cin >> x;

  // dp[i][j] = min cost to reach square j with jump length i
  const int maxJump = 1000;
  vector<vector<int>> dp(maxJump, vector<int>(n, 1e9));
  dp[0][0] = 0;
  for (int i = 1; i < maxJump; ++i) {
    for (int j = n - 1; j >= 0; --j) {
      if (j >= i && i) {
        dp[i][j] = dp[i - 1][j - i] + fees[j];
      }
      if (j + i < n) {
        dp[i][j] = min(dp[i][j], dp[i][j + i] + fees[j]);
      }
    }
  }

  int ans = INT_MAX;
  for (auto& v : dp) {
    ans = min(ans, v[n - 1]);
  }
  cout << ans;
}
