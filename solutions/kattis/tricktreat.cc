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

  cout << fixed << setprecision(5);

  int N;
  while (cin >> N && N) {
    vector<double> x(N), y(N);
    for (int i = 0; i < N; ++i) {
      cin >> x[i] >> y[i];
    }

    auto f = [&](double m) {
      double mx = INT_MIN;
      for (int i = 0; i < N; ++i) {
        double dx = x[i] - m;
        mx = max(mx, dx * dx + y[i] * y[i]);
      }
      return mx;
    };

    double l = -2e6, r = 2e6;
    // while (r - l > 1e-6) {
    for (int i = 0; i < 100; ++i) {
      double m1 = l + (r - l) / 3;
      double m2 = r - (r - l) / 3;
      if (f(m1) < f(m2)) {
        r = m2;
      } else {
        l = m1;
      }
    }
    cout << r << " " << sqrt(f(r)) << "\n";
  }
}
