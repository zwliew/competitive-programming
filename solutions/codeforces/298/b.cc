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

  int t, sx, sy, ex, ey;
  cin >> t >> sx >> sy >> ex >> ey;
  string s;
  cin >> s;

  unordered_map<char, pair<int, int>> m = {
      {'S', {0, -1}},
      {'N', {0, 1}},
      {'E', {1, 0}},
      {'W', {-1, 0}},
  };
  int cur = 0;
  while (cur < t && (sx != ex || sy != ey)) {
    auto &[dx, dy] = m[s[cur]];
    if (abs(ex - sx - dx) < abs(ex - sx) || abs(ey - sy - dy) < abs(ey - sy)) {
      sx += dx;
      sy += dy;
    }
    ++cur;
  }

  if (sx == ex && sy == ey) {
    cout << cur;
  } else {
    cout << -1;
  }
}
