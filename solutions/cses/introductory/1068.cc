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
  cout << n << ' ';
  while (n != 1) {
    if (n & 1) {
      n = n * 3 + 1;
    } else {
      n /= 2;
    }
    cout << n << ' ';
  }
}
