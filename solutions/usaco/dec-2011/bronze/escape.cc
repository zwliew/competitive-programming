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
#define FILE "rblock"
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  // Brute force every possible subset of cows using bitmasks.
  // Alternative is to solve this with recursive backtracking
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto& x : a)
    cin >> x;

  int ans = 0;
  for (int i = 1; i < (1 << n); ++i) {
    vector<int> digits(31);
    bool ok = true;
    int cnt = 0;
    for (int j = 0; j < n && ok; ++j) {
      if (i & (1 << j)) {
        int k = 0;
        int tmp = a[j];
        while (tmp && ok) {
          digits[k] += tmp % 10;
          if (digits[k] >= 10) {
            ok = false;
            break;
          }
          ++k;
          tmp /= 10;
        }
        ++cnt;
      }
    }

    if (ok) {
      ans = max(ans, cnt);
    }
  }
  cout << ans;
}
