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

  int n, x;
  cin >> n >> x;
  int cnt = 0;
  for (long long i = 1; i * i <= x; ++i) {
    if (x % i == 0 && i <= n && (x / i) <= n) {
      cnt += 1 + (i * i != x);
    }
  }
  cout << cnt;

  // Alternative editorial solution
  // int cnt = 0;
  // for (int i = 1; i <= n; ++i) {
  //   if (x % i == 0 && x / i <= n)
  //     ++cnt;
  // }
  // cout << cnt;
}
