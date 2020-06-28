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

  int x, y;
  cin >> x >> y;
  int x1 = 0;
  int y1 = abs(x) + abs(y);
  if (y < 0) {
    y1 = -y1;
  }
  int x2 = abs(x) + abs(y);
  if (x < 0) {
    x2 = -x2;
  }
  int y2 = 0;
  if (x1 > x2) {
    swap(x2, x1);
    swap(y2, y1);
  }

  cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2;
}
