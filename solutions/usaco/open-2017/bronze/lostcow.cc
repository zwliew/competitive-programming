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
#define FILE "lostcow"
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int x, y;
  cin >> x >> y;
  int delta = 1, cur = x;
  int total = 0;
  while (true) {
    if ((y > cur && y <= x + delta) || (y < cur && x + delta <= y)) {
      cout << total + abs(y - cur);
      return 0;
    } else {
      total += abs(x + delta - cur);
      cur = x + delta;
      delta = -delta * 2;
    }
  }
}
