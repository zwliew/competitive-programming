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

  string a, b;
  cin >> a >> b;
  vector<vector<int>> dp(a.size() + 1, vector<int>(b.size() + 1));
  for (int i = 1; i <= a.size(); ++i) {
    for (int j = 1; j <= b.size(); ++j) {
      if (a[i - 1] == b[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
      }
      dp[i][j] = max({dp[i][j], dp[i - 1][j], dp[i][j - 1]});
    }
  }
  int i = a.size();
  int j = b.size();
  string ans;
  while (i && j) {
    if (a[i - 1] == b[j - 1]) {
      ans += a[i - 1];
      --i;
      --j;
    } else if (dp[i - 1][j] > dp[i][j - 1]) {
      --i;
    } else {
      --j;
    }
  }
  reverse(ans.begin(), ans.end());
  cout << ans;
}
