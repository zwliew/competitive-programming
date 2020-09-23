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
#define FILE "rblock"
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (auto& x : a)
    cin >> x;

  vector<int> dp(m + 1, 1e9), nxtdp(m + 1, 1e9);
  dp[0] = 0;

  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= m; ++j) {
      nxtdp[j] = 1e9;
      for (int k = 1; k * k <= j; ++k) {
        int cost = abs(a[i - 1] - k);
        nxtdp[j] = min(nxtdp[j], dp[j - k * k] + cost * cost);
      }
    }
    swap(nxtdp, dp);
  }
  cout << (dp[m] >= 1e9 ? -1 : dp[m]);
}
