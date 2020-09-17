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
#define FILE ""
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  // Binary search for the maximum number that I can defeat. Greedily use the
  // spells on the K largest monsters.
  int64_t n, d, k;
  cin >> n >> d >> k;
  vector<int> a(n);
  for (auto& x : a)
    cin >> x;
  sort(a.begin(), a.end());

  int l = 0, r = n + 1;
  while (l < r - 1) {
    int m = l + (r - l) / 2;
    int64_t total = 0;
    for (int i = 0; i < m; ++i) {
      if (m - i <= k) {
        total += a[i] / 2;
      } else {
        total += a[i];
      }
    }

    if (total > d) {
      r = m;
    } else {
      l = m;
    }
  }
  cout << l;
}
