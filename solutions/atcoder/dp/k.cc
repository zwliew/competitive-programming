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
  vector<int> a(n);
  vector<int> dp(k + 1);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    if (a[i] <= k) {
      dp[a[i]] = 1;
    }
  }

  for (int i = 1; i <= k; ++i) {
    for (int j = 0; j < n; ++j) {
      if (dp[i]) break;
      if (a[j] > i) continue;
      dp[i] = !dp[i - a[j]];
    }
    // cerr << dp[i] << '\n';
  }
  cout << (dp[k] ? "First" : "Second");
}
