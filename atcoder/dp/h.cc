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

using ll = long long;
using ld = long double;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int h, w;
  cin >> h >> w;
  vector<vector<bool>> grid(h, vector<bool>(w));
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      char c;
      cin >> c;
      if (c == '.') {
        grid[i][j] = 1;
      }
    }
  }
  vector<vector<int>> dp(h, vector<int>(w));
  dp[0][0] = 1;
  for (int i = 1; i < w; ++i) {
    dp[0][i] = dp[0][i - 1] && grid[0][i];
  }
  for (int i = 1; i < h; ++i) {
    dp[i][0] = dp[i - 1][0] && grid[i][0];
  }
  for (int i = 1; i < h; ++i) {
    for (int j = 1; j < w; ++j) {
      dp[i][j] =
          grid[i][j] ? (dp[i - 1][j] + dp[i][j - 1]) % ((int)1e9 + 7) : 0;
    }
  }
  cout << dp[h - 1][w - 1];
}
