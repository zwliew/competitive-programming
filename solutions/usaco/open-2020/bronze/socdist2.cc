#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "../../_library/cc/debug.h"
#define FILE "test"
#else
#define debug(...) 0
#define FILE "socdist2"
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int N;
  cin >> N;
  vector<pair<int, bool>> v(N);
  for (int i = 0; i < N; ++i) {
    cin >> v[i].first >> v[i].second;
  }
  sort(v.begin(), v.end());

  int d = INT_MAX;
  for (int i = 0; i < N; ++i) {
    if (!v[i].second) {
      if (i && v[i - 1].second) {
        d = min(d, v[i].first - v[i - 1].first - 1);
      }
      if (i + 1 < N && v[i + 1].second) {
        d = min(d, v[i + 1].first - v[i].first - 1);
      }
    }
  }

  int ans = 0;
  for (int i = 0; i < N;) {
    if (v[i].second) {
      ++ans;
      ++i;
      while (i < N && v[i].second && v[i].first - v[i - 1].first <= d) {
        ++i;
      }
      while (i < N && !v[i].second) {
        ++i;
      }
    }
  }
  cout << ans;
}
