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

  int n;
  cin >> n;
  int cnt = 0;
  for (int c = 1; c <= n; ++c) {
    for (int a = 1; a <= c; ++a) {
      int bsq = c * c - a * a;
      int b = sqrt(bsq);
      if (b >= a && c >= b && b * b == bsq) {
        ++cnt;
      }
    }
  }
  cout << cnt;
}

