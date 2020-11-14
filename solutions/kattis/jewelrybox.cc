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

  int T;
  cin >> T;
  cout << fixed << setprecision(6);
  while (T--) {
    int X, Y;
    cin >> X >> Y;
    auto f = [&](double h) {
      double a = X - 2 * h;
      double b = Y - 2 * h;
      return a * b * h;
    };
    double l = 0, r = (double)min(X, Y) / 2;
    for (int i = 0; i < 100; ++i) {
      double m1 = l + (r - l) / 3;
      double m2 = r - (r - l) / 3;
      if (f(m1) < f(m2)) {
        l = m1;
      } else {
        r = m2;
      }
    }
    cout << f(l) << "\n";
  }
}
