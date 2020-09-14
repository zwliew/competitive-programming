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

  // Brute force every starting index i, and check whether the following
  // constraints are satisfied:
  //
  // 1. For all indices j < i, min(a[j]) >= a[i]
  // 2. For all indices j > i, min(a[j]) - 1 >= a[i]
  int64_t n, x;
  cin >> n >> x;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    if (i < x) {
      --a[i];
    }
  }

  vector<int> suffixMin(n + 1);
  suffixMin[n] = INT_MAX;
  for (int i = n - 1; i >= 0; --i) {
    suffixMin[i] = min(suffixMin[i + 1], a[i]);
  }

  int ans = -1;
  int prefixMin = INT_MAX;
  for (int i = 0; i < n; ++i) {
    if (prefixMin >= a[i] && suffixMin[i + 1] - 1 >= a[i]) {
      ans = i;
      break;
    }
    prefixMin = min(prefixMin, a[i]);
  }

  for (int i = 0; i < n; ++i) {
    if (i == ans) {
      cout << n - i - 1 + x + (int64_t)a[i] * n << ' ';
    } else {
      cout << a[i] - a[ans] - (i > ans) << ' ';
    }
  }
}
