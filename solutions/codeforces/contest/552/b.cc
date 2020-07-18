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

  int64_t n;
  cin >> n;
  int64_t sum = 0;
  for (int64_t i = 1, j = 1; i <= 1e9 && i <= n; i *= 10, ++j) {
    sum += min(n - i + 1, i * 10 - i) * j;
  }
  cout << sum;
}
