#include <stdio.h>

#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <deque>
#include <ext/numeric>
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

typedef long long ll;
typedef long double ld;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  // 2 ways to count:
  // 1. Count the sets that don't contain the n-th integer.
  // 2. Count all possible sets and divide by 2 (mod 1e9 + 7).
  const int mod = 1e9 + 7;
  int n;
  cin >> n;
  int sum = n * (n + 1) / 2;
  if (sum % 2) {
    cout << 0;
    return 0;
  }
  sum /= 2;

  // Method 1: count sets not containing the n-th integer.
  // vector<vector<int>> dp(n, vector<int>(sum + 1));
  // dp[0][0] = 1;
  // for (int i = 1; i < n; ++i) {
  //   for (int j = 0; j <= sum; ++j) {
  //     dp[i][j] = dp[i - 1][j];
  //     if (j >= i) {
  //       dp[i][j] = (dp[i][j] + dp[i - 1][j - i]) % mod;
  //     }
  //   }
  // }
  // cout << dp[n - 1][sum];

  // Method 2: count all sets and divide by 2 (mod 1e9 + 7)
  vector<vector<int>> dp(n + 1, vector<int>(sum + 1));
  dp[0][0] = 1;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= sum; ++j) {
      dp[i][j] = dp[i - 1][j];
      if (j >= i) {
        dp[i][j] = (dp[i][j] + dp[i - 1][j - i]) % mod;
      }
    }
  }
  auto mexp = [](int64_t x, int e, int m) {
    int64_t res = 1;
    while (e) {
      if (e & 1) {
        res *= x;
        res %= m;
      }
      x *= x;
      x %= m;
      e >>= 1;
    }
    return res;
  };
  cout << (dp[n][sum] * mexp(2, mod - 2, mod)) % mod;
}
