#include <algorithm>
#include <array>
#include <bitset>
#include <chrono>
#include <climits>
#include <cmath>
#include <cstring>
#include <deque>
#include <ext/pb_ds/assoc_container.hpp>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#ifdef LOCAL
#include "../../_library/cc/debug.h"
#define FILE "test"
#else
#define debug(...) 0
#define FILE ""
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int n;
  cin >> n;
  vector<int> a(n), b(n - 1);
  for (auto& x : a)
    cin >> x;
  for (auto& x : b)
    cin >> x;

  const int m = 1e9 + 7;
  array<int64_t, 2> dp;
  dp[0] = a[0] + b[0];
  dp[1] = dp[0] - 1;
  for (int i = 1; i < n; ++i) {
    array<int64_t, 2> ndp;
    int bv = i < n - 1 ? b[i] : 0;
    for (int j = 0; j < 2; ++j) {
      ndp[j] = dp[0] * (a[i] + max(0, bv - j)) % m + dp[1] * b[i - 1] % m;
      ndp[j] %= m;
    }
    swap(dp, ndp);
  }
  cout << dp[0];
}
