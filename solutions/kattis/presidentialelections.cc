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

  int s;
  cin >> s;
  vector<pair<int, int>> states;
  int total = 0;
  int avail = 0;
  for (int i = 0; i < s; ++i) {
    int d, c, f, u;
    cin >> d >> c >> f >> u;
    if (c > f + u) {
      avail += d;
    } else if (c + u > f) {
      states.emplace_back(d, (f + u - c) / 2 + 1);
    }
    total += d;
  }

  vector<int> dp(total + 1, 1e9 + 1);
  dp[0] = 0;
  dp[avail] = 0;
  for (auto& [d, x] : states) {
    for (int i = total; i >= d; --i) {
      dp[i] = min(dp[i], dp[i - d] + x);
    }
  }

  int best = 1e9 + 1;
  for (int i = total / 2 + 1; i <= total; ++i) {
    best = min(best, dp[i]);
  }

  if (best > 1e9) {
    cout << "impossible";
  } else {
    cout << best;
  }
}
