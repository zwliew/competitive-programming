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

  int n;
  cin >> n;
  vector<pair<int, int>> p;
  for (int i = 0; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    p.emplace_back(x, y);
  }

  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    bool l = false, r = false, u = false, b = false;
    auto &[x1, y1] = p[i];
    for (int j = 0; j < n; ++j) {
      if (i == j)
        continue;
      auto &[x2, y2] = p[j];
      if (x2 > x1 && y2 == y1) {
        r = true;
      } else if (x2 < x1 && y2 == y1) {
        l = true;
      } else if (x2 == x1 && y2 > y1) {
        u = true;
      } else if (x2 == x1 && y2 < y1) {
        b = true;
      }
    }

    if (l && r && u && b) {
      ++cnt;
    }
  }

  cout << cnt;
}
