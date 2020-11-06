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

  int d, s;
  cin >> d >> s;
  double l = 1e-9;
  double r = 1e9;
  for (int i = 0; i < 100; ++i) {
    double m = (l + r) / 2;
    double cur = cosh(d / m / 2) * m - m - s;
    if (cur >= 0) {
      l = m;
    } else {
      r = m;
    }
  }
  cout << fixed << setprecision(4) << 2 * l * sinh(d / l / 2);
}
