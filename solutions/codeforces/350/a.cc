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

  int n, m;
  cin >> n >> m;
  int cmax = INT_MAX;
  int cmin = INT_MIN;
  int minX = INT_MAX;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    cmin = max(cmin, x);
    minX = min(minX, x);
  }
  for (int i = 0; i < m; ++i) {
    int x;
    cin >> x;
    cmax = min(cmax, x - 1);
  }
  
  cmin = max(cmin, minX * 2);
  if (cmin > cmax) {
    cout << -1;
  } else {
    cout << cmin;
  }
}
