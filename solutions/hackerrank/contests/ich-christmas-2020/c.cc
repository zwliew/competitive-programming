#include <bits/stdc++.h>
using namespace std;
#define debug(...) 0
#ifdef LOCAL
#include "../../_library/cc/debug.h"
#endif
// #define FILE

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
#if defined(FILE) && !defined(LOCAL)
  freopen(FILE ".in", "r", stdin), freopen(FILE ".out", "w", stdout);
#endif

  int N;
  cin >> N;
  int ans = INT_MIN;
  int tmin = INT_MAX;
  int cmax = 0;
  int cmin = 0;
  int total = 0;
  while (N--) {
    int x;
    cin >> x;
    total += x;
    cmax = max(cmax, 0) + x;
    cmin = min(cmin, 0) + x;
    tmin = min(tmin, cmin);
    ans = max(ans, cmax);
  }
  ans = max(ans, total - tmin);
  cout << ans;
}
