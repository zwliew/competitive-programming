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
  int x1;
  int y1;
  int x2;
  int y2;

  int64_t area() { return (int64_t)max(0, (x2 - x1)) * max(0, (y2 - y1)); }

  struct Rectangle intersection(Rectangle& other) {
    Rectangle rect;
    rect.x1 = max(x1, other.x1);
    rect.x2 = min(x2, other.x2);
    rect.y1 = max(y1, other.y1);
    rect.y2 = min(y2, other.y2);
    return rect;
  }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  Rectangle a, b, c;
  cin >> a.x1 >> a.y1 >> a.x2 >> a.y2 >> b.x1 >> b.y1 >> b.x2 >> b.y2 >> c.x1 >>
      c.y1 >> c.x2 >> c.y2;

  auto area = a.area() - a.intersection(b).area() - a.intersection(c).area() +
              a.intersection(b).intersection(c).area();
  if (area) {
    cout << "YES";
  } else {
    cout << "NO";
  }
}
