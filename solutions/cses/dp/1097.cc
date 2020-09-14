#include <stdio.h>

#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <deque>
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

  int n;
  cin >> n;
  vector<int> x(n);
  for (int& i : x) {
    cin >> i;
  }
  vector<vector<ll>> dp(n, vector<ll>(n));
  for (int i = n - 1; i >= 0; --i) {
    for (int j = i; j < n; ++j) {
      if (i == j) {
        dp[i][j] = x[i];
      } else {
        dp[i][j] = max(x[i] - dp[i + 1][j], x[j] - dp[i][j - 1]);
      }
    }
  }
  cout << (accumulate(x.begin(), x.end(), 0ll) + dp[0][n - 1]) / 2;

  // Alternative DP solution
  // for (int i = n - 1; i >= 0; --i) {
  //   for (int j = i; j < n; ++j) {
  //     if (i == j) {
  //       dp[i][j] = a[i];
  //     } else {
  //       dp[i][j] = max(
  //           a[i] + min(i + 2 < n ? dp[i + 2][j] : INT_MAX, dp[i + 1][j - 1]),
  //           a[j] + min(dp[i + 1][j - 1], j - 2 >= 0 ? dp[i][j - 2] :
  //           INT_MAX));
  //     }
  //   }
  // }
  // cout << dp[0][n - 1];
}
