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
#define FILE "socdist"
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int n, m;
  cin >> n >> m;
  vector<pair<int64_t, int64_t>> intervals(m);
  for (int i = 0; i < m; ++i) {
    cin >> intervals[i].first >> intervals[i].second;
  }
  sort(intervals.begin(), intervals.end());

  int64_t l = 1, r = 1e18 + 1;
  while (l < r - 1) {
    int64_t mid = l + (r - l) / 2;
    int64_t prev = -1e18 - 1;
    int64_t cnt = 0;
    for (int j = 0; cnt < n && j < m; ++j) {
      if (prev + mid > intervals[j].second)
        continue;
      int64_t start = max(prev + mid, intervals[j].first);
      int64_t placed = (intervals[j].second - start) / mid;
      int64_t end = start + mid * placed;
      cnt += placed + 1;
      prev = end;
    }

    if (cnt >= n) {
      l = mid;
    } else {
      r = mid;
    }
  }

  cout << l;
}
