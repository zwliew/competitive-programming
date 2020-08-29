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

  int m, n;
  cin >> m >> n;
  vector<int> t(n), z(n), y(n);
  for (int i = 0; i < n; ++i) {
    cin >> t[i] >> z[i] >> y[i];
  }

  int lo = 0, hi = 1e9;
  vector<int> best;
  while (lo < hi) {
    int mid = lo + (hi - lo) / 2;
    vector<int> cnt(n);
    for (int i = 0; i < n; ++i) {
      int interval = t[i] * z[i] + y[i];
      int rem = mid % interval;
      cnt[i] = mid / interval * z[i] + min(z[i], rem / t[i]);
    }

    if (accumulate(cnt.begin(), cnt.end(), 0) >= m) {
      hi = mid;
      best = cnt;
    } else {
      lo = mid + 1;
    }
  }

  cout << hi << "\n";
  for (int x : best) {
    cout << min(m, x) << " ";
    m -= x;
  }
}
