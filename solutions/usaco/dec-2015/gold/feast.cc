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
#define FILE "feast"
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int t, a, b;
  cin >> t >> a >> b;

  vector<bool> dp(t + 1);
  dp[0] = true;
  for (int i = 1; i <= t; ++i) {
    if (i >= a) {
      dp[i] = dp[i] || dp[i - a];
    }
    if (i >= b) {
      dp[i] = dp[i] || dp[i - b];
    }
  }
  for (int i = 1; i <= t; ++i) {
    if (i * 2 <= t) {
      dp[i] = dp[i] || dp[i * 2];
    }
    if (i * 2 < t) {
      dp[i] = dp[i] || dp[i * 2 + 1];
    }
  }

  int ans = 0;
  for (int i = 1; i <= t; ++i) {
    if (i >= a) {
      dp[i] = dp[i] || dp[i - a];
    }
    if (i >= b) {
      dp[i] = dp[i] || dp[i - b];
    }
    if (dp[i]) {
      ans = max(ans, i);
    }
  }
  cout << ans;
}
