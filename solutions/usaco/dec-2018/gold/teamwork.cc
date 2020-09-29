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
#define FILE "teamwork"
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int n, k;
  cin >> n >> k;
  vector<int> skill(n);
  for (int i = 0; i < n; ++i)
    cin >> skill[i];

  vector<int> dp(n + 1);
  for (int i = 1; i <= n; ++i) {
    int curMax = 0;
    for (int j = 1; j <= min(i, k); ++j) {
      curMax = max(curMax, skill[i - j]);
      dp[i] = max(dp[i], dp[i - j] + curMax * j);
    }
  }
  cout << dp[n];
}
