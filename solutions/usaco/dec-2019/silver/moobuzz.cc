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
#define FILE "moobuzz"
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int n;
  cin >> n;

  int64_t l = 0, r = 1e18;
  while (l < r - 1) {
    int64_t m = l + (r - l) / 2;
    int64_t cnt3 = m / 3;
    int64_t cnt5 = m / 5;
    int64_t cnt15 = m / 15;
    if (m - cnt3 - cnt5 + cnt15 >= n) {
      r = m;
    } else {
      l = m;
    }
  }
  cout << r;
}
