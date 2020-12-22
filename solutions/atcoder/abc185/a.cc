#include <bits/stdc++.h>

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

  int ans = INT_MAX;
  for (int i = 0; i < 4; ++i) {
    int x;
    cin >> x;
    ans = min(ans, x);
  }
  cout << ans;
}
