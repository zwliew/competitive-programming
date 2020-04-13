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

  int n;
  cin >> n;
  vector<int> h(n);
  for (int i = 0; i < n; ++i) {
    cin >> h[i];
  }
  vector<int> dp(n);
  for (int i = 1; i < n; ++i) {
    dp[i] = dp[i - 1] + abs(h[i] - h[i - 1]);
    if (i >= 2) {
      dp[i] = min(dp[i], dp[i - 2] + abs(h[i] - h[i - 2]));
    }
  }
  cout << dp[n - 1];
}
