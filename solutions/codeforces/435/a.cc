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
  int ans = 1;
  int cur = 0;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    if (cur + a <= m) {
      cur += a;
    } else {
      ++ans;
      cur = a;
    }
  }
  cout << ans;
}
