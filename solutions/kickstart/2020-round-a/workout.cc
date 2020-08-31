/*
ID: zhaowei10
TASK:
LANG: C++14
*/
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <cmath>
#include <deque>
#include <fstream>
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

  int t;
  cin >> t;
  for (int ti = 1; ti <= t; ++ti) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto& x : a)
      cin >> x;

    int l = 0, r = 1e9;
    while (l < r - 1) {
      int m = l + (r - l) / 2;

      int total = 0;
      for (int i = 0; i < n - 1; ++i) {
        int d = (a[i + 1] - a[i] + m - 1) / m - 1;
        total += d;
      }

      if (total <= k) {
        r = m;
      } else {
        l = m;
      }
    }

    cout << "Case #" << ti << ": " << r << "\n";
  }
}
