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

  // Rotate the struck point and use trigonometry and circles
  const long double pi = 2 * acos(0);
  long double r, x, y;
  while (cin >> r >> x >> y) {
    auto d = hypot(x, y);
    if (d > r) {
      cout << "miss";
    } else {
      auto area = pi * r * r;
      auto clen = 2 * sqrt(r * r - d * d);
      auto theta = 2 * asin(clen / 2 / r);
      auto darea = (theta - sin(theta)) / 2 * r * r;
      cout << max(area - darea, darea) << ' ' << min(area - darea, darea);
    }
    cout << "\n";
  }
}
