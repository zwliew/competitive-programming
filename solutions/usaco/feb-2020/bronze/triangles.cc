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
#define FILE "triangles"
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int n;
  cin >> n;
  vector<array<int, 2>> points(n);
  for (int i = 0; i < n; ++i) {
    cin >> points[i][0] >> points[i][1];
  }

  int best = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (points[j][1] != points[i][1])
        continue;
      for (int k = 0; k < n; ++k) {
        if (points[k][0] != points[i][0])
          continue;
        best = max(best, abs(points[j][0] - points[i][0]) *
                             abs(points[k][1] - points[i][1]));
      }
    }
  }

  cout << best;
}
