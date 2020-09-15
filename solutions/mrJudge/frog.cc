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

  // Straightforward brute force + prefix/suffix mins.
  int n;
  cin >> n;
  vector<int> heights(n);
  for (auto& x : heights)
    cin >> x;

  vector<int> suffixMin(n);
  suffixMin[n - 1] = INT_MAX;
  for (int i = n - 2; i >= 0; --i) {
    suffixMin[i] = min(suffixMin[i + 1], heights[i + 1]);
  }
  int prefixMin = heights[0];

  int best = 0;
  for (int i = 1; i < n - 1; ++i) {
    if (prefixMin < heights[i] && heights[i] > suffixMin[i]) {
      best = max(best, 2 * heights[i] - prefixMin - suffixMin[i]);
    }
    prefixMin = min(prefixMin, heights[i]);
  }
  cout << best;
}
