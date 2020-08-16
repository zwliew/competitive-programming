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
#define FILE "billboard"
#endif

struct Rectangle {
  int x1, x2, y1, y2;
};

int calcRemainingArea(Rectangle& a, Rectangle& b) {
  int res = (a.x2 - a.x1) * (a.y2 - a.y1);
  int x = max(0, min(a.x2, b.x2) - max(a.x1, b.x1));
  int y = max(0, min(a.y2, b.y2) - max(a.y1, b.y1));
  return res - x * y;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  Rectangle a, b, c;
  cin >> a.x1 >> a.y1 >> a.x2 >> a.y2;
  cin >> b.x1 >> b.y1 >> b.x2 >> b.y2;
  cin >> c.x1 >> c.y1 >> c.x2 >> c.y2;

  cout << calcRemainingArea(a, c) + calcRemainingArea(b, c);
}
