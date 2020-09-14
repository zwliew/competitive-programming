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

  // Constructive problem technique: try to find the optimal number, and
  // construct a solution that achieves that optimal number.
  //
  // In this case, the optimal number is the min length of all subarrays (easy
  // to see).
  // An easy construction that achieves this is by looping over all the
  // numbers from 0 to that number.
  int n, m;
  cin >> n >> m;
  int minLen = INT_MAX;
  while (m--) {
    int l, r;
    cin >> l >> r;
    minLen = min(minLen, r - l + 1);
  }

  cout << minLen << '\n';
  for (int i = 0; i < n; ++i) {
    cout << i % minLen << ' ';
  }
}
