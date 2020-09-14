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

  // Binary search on the min time
  // Could also use brute force + observation or DP
  int n, k, p;
  cin >> n >> k >> p;
  vector<int> a(n), b(k);
  for (auto& x : a)
    cin >> x;
  for (auto& x : b)
    cin >> x;
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  int64_t l = -1, r = 1e18;
  while (l < r - 1) {
    auto m = l + (r - l) / 2;
    bool ok = true;
    for (int i = 0, j = 0; i < a.size() && ok; ++i, ++j) {
      while (j < b.size() && abs(a[i] - b[j]) + abs(p - b[j]) > m) {
        ++j;
      }
      if (j == b.size()) {
        ok = false;
      }
    }

    if (ok) {
      r = m;
    } else {
      l = m;
    }
  }

  cout << r;
}
