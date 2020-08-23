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
#define FILE "balancing"
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (auto& x : a)
    cin >> x;

  double lo = 0, hi = 1e9;
  for (int i = 0; i < 100; ++i) {
    auto m = lo + (hi - lo) / 2;
    int cnt = 0;
    for (int x : a) {
      cnt += x / m;
    }
    if (cnt >= k) {
      lo = m;
    } else {
      hi = m;
    }
  }
  cout << fixed << setprecision(6) << lo;
}
