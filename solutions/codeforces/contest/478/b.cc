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

  int64_t n, m;
  cin >> n >> m;
  auto mx = (n - m + 1) * (n - m) / 2;
  auto rem = n % m;
  auto mn =
      (m - rem) * (n / m) * (n / m - 1) / 2 + rem * (n / m + 1) * (n / m) / 2;
  cout << mn << ' ' << mx;
}
