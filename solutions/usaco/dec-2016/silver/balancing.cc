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

void countQuadrants(array<int, 4>& cnt,
                    vector<array<int, 2>>& pts,
                    int x,
                    int y) {
  for (int i = 0; i < pts.size(); ++i) {
    int cx = pts[i][0];
    int cy = pts[i][1];
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
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int n;
  cin >> n;
  vector<array<int, 2>> pts(n);
  vector<int> xPts(n), yPts(n);
  for (int i = 0; i < n; ++i) {
    cin >> xPts[i] >> yPts[i];
    pts[i] = {xPts[i], yPts[i]};
  }
  sort(xPts.begin(), xPts.end());
  sort(yPts.begin(), yPts.end());
  sort(pts.begin(), pts.end());

  int best = INT_MAX;

  // Sweep line solution
  for (int i = 0; i < n; ++i) {
    int y = yPts[i] + 1;
    array<int, 4> cnt{};
    countQuadrants(cnt, pts, 0, y);
    best = min(best, *max_element(cnt.begin(), cnt.end()));

    for (int j = 0; j < n; ++j) {
      if (pts[j][1] < y) {
        --cnt[2];
        ++cnt[0];
      } else {
        --cnt[3];
        ++cnt[1];
      }
      best = min(best, *max_element(cnt.begin(), cnt.end()));
    }
  }

  // Binary search solution. Passes test cases but not sure
  // if it is correct.
  //
  // for (int i = 0; i < n; ++i) {
  //   int x = xPts[i] + 1;
  //   int lo = 0, hi = n - 1;
  //   while (lo < hi) {
  //     int m = lo + (hi - lo + 1) / 2;
  //     array<int, 4> cnt{};
  //     int y = yPts[i] + 1;
  //     countQuadrants(cnt, pts, x, y);

  //     best = min(best, *max_element(cnt.begin(), cnt.end()));
  //     if (cnt[0] + cnt[2] <= cnt[1] + cnt[3]) {
  //       lo = m;
  //     } else {
  //       hi = m - 1;
  //     }
  //   }
  // }

  cout << best;
}
