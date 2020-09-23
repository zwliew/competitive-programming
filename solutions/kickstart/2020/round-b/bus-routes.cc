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

  // Binary search for the latest starting date, and take buses as early as
  // possible (multiples of X_i).
  //
  // Alternative: solve this in linear time by working backwards from the latest
  // possible date to take the last bus.
  int t;
  cin >> t;
  for (int ti = 1; ti <= t; ++ti) {
    cout << "Case #" << ti << ": ";

    int n;
    int64_t d;
    cin >> n >> d;
    vector<int64_t> a(n);
    for (auto& x : a)
      cin >> x;

    // Binary search solution
    // int64_t l = 1;
    // int64_t r = d + 1;
    // while (l < r - 1) {
    //   int64_t m = l + (r - l) / 2;
    //   int64_t curD = m;
    //   for (auto x : a) {
    //     int64_t div = (curD + x - 1) / x;
    //     curD = div * x;
    //   }
    //   if (curD <= d) {
    //     l = m;
    //   } else {
    //     r = m;
    //   }
    // }
    // cout << l << "\n";

    // Linear time solution: work backwards from d
    int64_t cur = d;
    for (int i = n - 1; i >= 0; --i) {
      cur = cur - cur % a[i];
    }
    cout << cur << "\n";
  }
}
