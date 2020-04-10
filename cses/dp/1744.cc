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

  int a, b;
  cin >> a >> b;

  vector<vector<int>> dp(a + 1, vector<int>(b + 1, 1e9));
  for (int i = 0; i <= a; ++i) {
    for (int j = 0; j <= b; ++j) {
      if (i == j) {
        dp[i][j] = 0;
      } else {
        for (int k = 1; k < i; ++k) {
          dp[i][j] = min(dp[i][j], dp[i - k][j] + dp[k][j] + 1);
        }
        for (int k = 1; k < j; ++k) {
          dp[i][j] = min(dp[i][j], dp[i][j - k] + dp[i][k] + 1);
        }
      }
    }
  }
  cout << dp[a][b];
}
