#include <algorithm>
#include <array>
#include <bitset>
#include <chrono>
#include <climits>
#include <cmath>
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
//#include "bits/stdc++.h"

using namespace std;

#ifdef LOCAL
#include "../../_library/cc/debug.h"
#define FILE "test"
#else
#define debug(...) 0
#define FILE "moocast"
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int n;
  cin >> n;
  vector<int> c(n);
  for (auto& x : c)
    cin >> x;
  vector<string> orig(n), rev(n);
  for (int i = 0; i < n; ++i) {
    cin >> orig[i];
    rev[i] = orig[i];
    reverse(rev[i].begin(), rev[i].end());
  }

  vector<vector<int64_t>> dp(n, vector<int64_t>(2, 1e18));
  dp[0][0] = 0;
  dp[0][1] = c[0];
  for (int i = 1; i < n; ++i) {
    if (orig[i - 1] <= orig[i]) {
      dp[i][0] = dp[i - 1][0];
    }
    if (rev[i - 1] <= orig[i]) {
      dp[i][0] = min(dp[i][0], dp[i - 1][1]);
    }
    if (orig[i - 1] <= rev[i]) {
      dp[i][1] = dp[i - 1][0];
    }
    if (rev[i - 1] <= rev[i]) {
      dp[i][1] = min(dp[i][1], dp[i - 1][1]);
    }
    dp[i][1] += c[i];
  }

  auto ans = min(dp[n - 1][0], dp[n - 1][1]);
  cout << (ans >= 1e18 ? -1 : ans);
}
