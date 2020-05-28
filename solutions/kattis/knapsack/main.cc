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

  int c, n;
  while (cin >> c >> n) {
    vector<pair<int, int>> obj(n);
    for (auto &[v, w] : obj) {
      cin >> v >> w;
    }
    vector<vector<int>> dp(n + 1, vector<int>(c + 1));
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= c; ++j) {
        dp[i][j] = dp[i - 1][j];
        if (j >= obj[i - 1].second) {
          dp[i][j] = max(dp[i][j],
                         dp[i - 1][j - obj[i - 1].second] + obj[i - 1].first);
        }
      }
    }

    vector<int> output;
    int i = n, j = c;
    while (dp[i][j] != 0) {
      if (dp[i][j] != dp[i - 1][j]) {
        output.push_back(i - 1);
        j -= obj[i - 1].second;
      }
      --i;
    }
    reverse(output.begin(), output.end());
    cout << output.size() << '\n';
    for (int x : output) {
      cout << x << ' ';
    }
    cout << '\n';
  }
}
