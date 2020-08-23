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
#define FILE "balancing"
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int n, b;
  cin >> n >> b;
  vector<array<int, 2>> coords(n);
  for (int i = 0; i < n; ++i) {
    cin >> coords[i][0] >> coords[i][1];
  }

  int best = INT_MAX;
  for (int xi = 0; xi < n; ++xi) {
    int x = coords[xi][0] + 1;
    for (int yi = 0; yi < n; ++yi) {
      int y = coords[yi][1] + 1;
      array<int, 4> cnt{};
      for (int i = 0; i < n; ++i) {
        int cx = coords[i][0];
        int cy = coords[i][1];
        if (cx < x && cy < y) {
          ++cnt[0];
        } else if (cx < x) {
          ++cnt[1];
        } else if (cy < y) {
          ++cnt[2];
        } else {
          ++cnt[3];
        }
      }
      best = min(best, *max_element(cnt.begin(), cnt.end()));
    }
  }
  cout << best;
}
