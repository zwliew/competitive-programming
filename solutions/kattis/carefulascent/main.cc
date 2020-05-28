#include <stdio.h>

#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <deque>
#include <fstream>
#include <functional>
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

  // Binary search for the correct horizontal velocity, brute force the
  // horizontal position for a given horizontal velocity (max of 100 shields).
  //
  // This problem is interesting because it requires us to binary search on real
  // values. Be cautious and use epsilon values when comparing ranges.
  int x, y, n;
  cin >> x >> y >> n;
  bool neg = 0;
  if (x < 0) {
    neg = 1;
    x = -x;
  }

  vector<pair<int, ld>> shields(n);  // duration, factor
  int remaining = y;
  for (auto &[duration, factor] : shields) {
    int l, u;
    cin >> l >> u >> factor;
    duration = u - l;
    remaining -= duration;
  }
  shields.emplace_back(remaining, 1);

  const ld eps = 1e-7;
  ld lo = 0, hi = x;
  // It is not wise to simply compare (lo + eps < hi).
  // See: https://codeforces.com/blog/entry/63085
  // Instead, iterate a fixed number of times. 300 should be more than enough.
  for (int i = 0; i < 300 && lo + eps < hi; ++i) {
    ld mid = lo + (hi - lo) / 2;
    ld cur = 0;
    for (auto &[duration, factor] : shields) {
      cur += duration * factor * mid;
    }
    if (cur + eps < x) {
      lo = mid;
    } else {
      hi = mid;
    }
  }

  cout << fixed << setprecision(6) << (lo + (hi - lo) / 2) * (neg ? -1 : 1);
}
