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
#define FILE ""
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int n, vb, vs;
  cin >> n >> vb >> vs;
  vector<int> coords(n);
  for (auto& x : coords)
    cin >> x;
  int x, y;
  cin >> x >> y;

  long double bestTime = INT_MAX;
  int bestIdx = -1;
  for (int i = 1; i < n; ++i) {
    long double curDist = hypotl(x - coords[i], y);
    long double curTime =
        (long double)coords[i] / vb + (long double)curDist / vs;
    if (curTime <= bestTime) {
      bestTime = curTime;
      bestIdx = i;
    }
  }

  cout << bestIdx + 1;
}
