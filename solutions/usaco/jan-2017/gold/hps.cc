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
//#include "bits/stdc++.h"

using namespace std;

#ifdef LOCAL
#include "../../_library/cc/debug.h"
#define FILE "test"
#else
#define debug(...) 0
#define FILE "hps"
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  // dp[i][j][k] = the max. wins I can get if I've played i games and used  up
  // to j switches while ending on the kth gesture
  int n, switches;
  cin >> n >> switches;

  array<char, 3> ctoi = {'H', 'P', 'S'};
  vector<vector<int>> dp(switches + 1, vector<int>(3)),
      nxtdp(switches + 1, vector<int>(3));
  for (int i = 1; i <= n; ++i) {
    char c;
    cin >> c;
    auto ci = find(ctoi.begin(), ctoi.end(), c) - ctoi.begin();
    for (int j = 0; j <= switches; ++j) {
      for (int k = 0; k < 3; ++k) {
        nxtdp[j][k] = dp[j][k];
        if (j) {
          nxtdp[j][k] =
              max({nxtdp[j][k], dp[j - 1][0], dp[j - 1][1], dp[j - 1][2]});
        }
        nxtdp[j][k] += ci == (k + 2) % 3;
      }
    }
    swap(dp, nxtdp);
  }
  cout << *max_element(dp[switches].begin(), dp[switches].end());
}
