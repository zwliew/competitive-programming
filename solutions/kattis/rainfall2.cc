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
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

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

  double l, k, t1, t2, h;
  cin >> l >> k >> t1 >> t2 >> h;

  cout << fixed << setprecision(6);
  if (h < l) {
    cout << h << " " << h;
    return 0;
  }

  if (h == l) {
    cout << h << " ";
  } else {
    double lo = h;
    double hi = 1e9;
    for (int i = 0; i < 100; ++i) {
      double m = (lo + hi) / 2;
      double t = l / m * t1;
      double cur = m - (t1 - t + t2) * k;
      if (cur >= h) {
        hi = m;
      } else {
        lo = m;
      }
    }
    cout << hi << " ";
  }

  double lo = h;
  double hi = 1e9;
  for (int i = 0; i < 100; ++i) {
    double m = (lo + hi) / 2;
    double t = l / m * t1;
    double cur = m - (t1 - t + t2) * k;
    if (cur <= h) {
      lo = m;
    } else {
      hi = m;
    }
  }
  cout << lo;
}
