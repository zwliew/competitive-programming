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

  int n, k;
  cin >> n >> k;
  vector<int> h(n);
  for (int i = 0; i < n; ++i) {
    cin >> h[i];
  }
  vector<int> dp(n, 1e9);
  dp[0] = 0;
  for (int i = 1; i < n; ++i) {
    for (int j = 1; j <= min(k, i); ++j) {
      dp[i] = min(dp[i], dp[i - j] + abs(h[i] - h[i - j]));
    }
  }
  cout << dp[n - 1];
}
