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

  int mod = 1e9 + 7;
  int n;
  cin >> n;
  if (n * (n + 1) % 4) {
    cout << 0;
    return 0;
  }
  int target = n * (n + 1) / 4;
  vector<vector<int>> dp(n, vector<int>(target + 1));
  dp[0][0] = 1;
  for (int i = 1; i < n; ++i) {
    for (int j = 0; j <= target; ++j) {
      if (!j) {
        dp[i][j] = 1;
      } else if (i) {
        dp[i][j] = dp[i - 1][j];
        if (j >= i) {
          dp[i][j] = (dp[i][j] + dp[i - 1][j - i]) % mod;
        }
      }
    }
  }
  cout << dp[n - 1][target];
}
