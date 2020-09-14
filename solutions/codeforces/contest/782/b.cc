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
//#include "bits/stdc++.h"

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

  // Binary search for the minimum time such that the intersecting segment
  // visitable by all people has non-zero length.
  int n;
  cin >> n;
  vector<int> a(n), v(n);
  for (auto& x : a)
    cin >> x;
  for (auto& x : v)
    cin >> x;

  // Binary search on real numbers
  long double l = -1;
  long double r = 1e9;
  for (int t = 0; t < 100; ++t) {
    auto m = l + (r - l) / 2;
    long double mn = 1;
    long double mx = 1e9;
    for (int i = 0; i < n; ++i) {
      auto d = v[i] * m;
      mn = max(mn, a[i] - d);
      mx = min(mx, a[i] + d);
    }

    if (mn <= mx) {
      r = m;
    } else {
      l = m;
    }
  }
  cout << fixed << setprecision(6) << r;
}
