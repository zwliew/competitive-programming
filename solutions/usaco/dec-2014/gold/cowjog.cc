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
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
// #include "bits/stdc++.h"

using namespace std;

#ifdef LOCAL
#include "../../_library/cc/debug.h"
#define FILE "test"
#else
#define debug(...) 0
#define FILE "cowjog"
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  // Similar to the LIS problem
  int64_t n, t;
  cin >> n >> t;

  vector<int64_t> dp;
  for (int i = 0; i < n; ++i) {
    int64_t p, v;
    cin >> p >> v;
    auto x = -(p + v * t);
    auto it = upper_bound(dp.begin(), dp.end(), x);
    if (it != dp.end()) {
      *it = x;
    } else {
      dp.push_back(x);
    }
  }
  cout << dp.size();
}
