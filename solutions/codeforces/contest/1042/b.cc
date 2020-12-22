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
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <random>
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
#define FILE ""
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  const int INF = 1e9;
  int N;
  cin >> N;
  vector<int> juices(8, INF);
  for (int i = 0; i < N; ++i) {
    int p;
    string s;
    cin >> p >> s;
    int cur = 0;
    for (char c : s) {
      cur |= 1 << (c - 'A');
    }
    juices[cur] = min(juices[cur], p);
  }

  // DP solution (knapsack-esque)
  vector<int> dp(8, INF);
  dp[0] = 0;
  for (int i = 1; i < 8; ++i) {
    for (int k = 1; k < 8; ++k) {
      if (k & i) {
        dp[i] = min(dp[i], dp[i & ~k] + juices[k]);
      }
    }
  }
  cout << (dp[7] >= INF ? -1 : dp[7]);

  // Brute force solution (only 8 unique drinks; try all subsets of them)
  // int64_t ans = INF;
  // for (int i = 1; i < (1 << 8); ++i) {
  //   int cur = 0;
  //   int j = i;
  //   int64_t cost = 0;
  //   while (j) {
  //     int lst = j & -j;
  //     cur |= __builtin_ctz(lst);
  //     cost += juices[__builtin_ctz(lst)];
  //     j -= lst;
  //   }
  //   if (cur == 7) {
  //     ans = min(ans, cost);
  //   }
  // }
  // cout << (ans >= INF ? -1 : ans);
}
