#include <bits/stdc++.h>
using namespace std;
#define debug(...) 0
#ifdef LOCAL
#include "../../_library/cc/debug.h"
#endif
// #define FILE "milkvisits"

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
#if defined(FILE) && !defined(LOCAL)
  freopen(FILE ".in", "r", stdin), freopen(FILE ".out", "w", stdout);
#endif

  int T;
  cin >> T;
  while (T--) {
    int sx, sy, ex, ey;
    cin >> sx >> sy >> ex >> ey;
    int dx = abs(ex - sx);
    int dy = abs(sy - ey);
    int delta = max(abs(dx - dy) - 1, 0);
    delta += delta % 2;
    cout << (int64_t)dx + dy + delta << "\n";
  }
}
