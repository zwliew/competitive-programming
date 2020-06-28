/*
ID: zhaowei10
TASK:
LANG: C++14
*/
#include "bits/stdc++.h"

using namespace std;

#ifdef LOCAL
#include "../../_library/cpp/debug.h"
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

  int64_t n, m, k;
  cin >> n >> m >> k;

  vector<int64_t> a(n + 1), b(m + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    a[i] += a[i - 1];
  }
  for (int i = 1; i <= m; ++i) {
    cin >> b[i];
    b[i] += b[i - 1];
  }

  int64_t best = 0;
  for (int i = 0; i <= n; ++i) {
    int64_t rem = k - a[i];
    if (rem < 0)
      continue;
    auto it = upper_bound(b.begin(), b.end(), rem);
    best = max(best, i + distance(b.begin(), it) - 1);
  }

  cout << best;
}
