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

  int x1, x2, y1, y2;
  cin >> x1 >> y1 >> x2 >> y2;

  int dy = abs(y1 - y2);
  int dx = abs(x1 - x2);
  if (!dx) {
    cout << x1 + dy << ' ' << y1 << ' ' << x1 + dy << ' ' << y2;
  } else if (!dy) {
    cout << x1 << ' ' << y1 + dx << ' ' << x2 << ' ' << y2 + dx;
  } else if (dx == dy) {
    cout << x1 << ' ' << y2 << ' ' << x2 << ' ' << y1;
  } else {
    cout << -1;
  }
}
