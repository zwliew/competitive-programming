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
#define FILE "pails"
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int x, y, z;
  cin >> x >> y >> z;
  int best = 0;
  for (int i = 0; i * x <= z; ++i) {
    for (int j = 0; j * y <= z - i * x; ++j) {
      best = max(best, i * x + j * y);
    }
  }
  cout << best;
}
