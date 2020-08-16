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

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  Rectangle a, b;
  cin >> a.x1 >> a.y1 >> a.x2 >> a.y2;
  cin >> b.x1 >> b.y1 >> b.x2 >> b.y2;

  int intersectW = max(min(a.x2, b.x2) - max(a.x1, b.x1), 0);
  int intersectH = max(min(a.y2, b.y2) - max(a.y1, b.y1), 0);
  int area = (a.x2 - a.x1) * (a.y2 - a.y1);
  if ((intersectW == a.x2 - a.x1 && (b.y1 <= a.y1 || b.y2 >= a.y2)) ||
      (intersectH == a.y2 - a.y1 && (b.x1 <= a.x1 || b.x2 >= a.x2))) {
    cout << area - intersectW * intersectH;
  } else {
    cout << area;
  }
}
