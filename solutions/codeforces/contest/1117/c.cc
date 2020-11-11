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

  int sx, sy, tx, ty, n;
  string s;
  cin >> sx >> sy >> tx >> ty >> n >> s;
  vector<int> pdx(n), pdy(n);
  for (int i = 0; i < n; ++i) {
    if (i) {
      pdx[i] = pdx[i - 1];
      pdy[i] = pdy[i - 1];
    }
    if (s[i] == 'U') {
      ++pdy[i];
    } else if (s[i] == 'D') {
      --pdy[i];
    } else if (s[i] == 'L') {
      --pdx[i];
    } else {
      ++pdx[i];
    }
  }

  int64_t l = -1, r = 1e18;
  while (l < r - 1) {
    int64_t m = l + (r - l) / 2;
    int64_t q = m / n;
    int64_t rem = m % n;
    int64_t x = q * pdx.back() + (rem ? pdx[rem - 1] : 0) + sx;
    int64_t y = q * pdy.back() + (rem ? pdy[rem - 1] : 0) + sy;
    int64_t d = abs(tx - x) + abs(ty - y);
    if (d <= m) {
      r = m;
    } else {
      l = m;
    }
  }
  cout << (r == int64_t(1e18) ? -1 : r);
}
