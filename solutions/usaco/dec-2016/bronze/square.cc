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
#define FILE "square"
#endif

struct Rectangle {
  int x1;
  int y1;
  int x2;
  int y2;
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
  int w = max(a.x2, b.x2) - min(a.x1, b.x1);
  int h = max(a.y2, b.y2) - min(a.y1, b.y1);
  cout << max(w, h) * max(w, h);
}
