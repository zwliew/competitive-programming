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
  int ans = 0;
  int cur = 0;
  int prev = 0;
  while (n--) {
    int x, y;
    cin >> x >> y;
    y += x * 60;
    if (y == prev) {
      ++cur;
    } else {
      cur = 1;
    }
    prev = y;
    ans = max(ans, cur);
  }
  cout << ans;
}

