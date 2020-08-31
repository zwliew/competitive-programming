/*
ID: zhaowei10
TASK:
LANG: C++14
*/
#include "bits/stdc++.h"

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

  int n;
  cin >> n;
  vector<pair<int, int>> a(n);
  for (auto& [x, v] : a)
    cin >> x >> v;

  double l = 0, r = 1e9;
  for (int i = 0; i < 100; ++i) {
    double m = l + (r - l) / 2;
    double mn = INT_MIN;
    double mx = INT_MAX;
    for (auto& [x, v] : a) {
      double d = v * m;
      mn = max(mn, x - d);
      mx = min(mx, x + d);
    }

    if (mn <= mx) {
      r = m;
    } else {
      l = m;
    }
  }

  cout << fixed << setprecision(6) << r;
}
