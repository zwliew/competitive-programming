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
#define FILE "cbarn"
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int n;
  cin >> n;
  vector<int> r(n);
  for (int i = 0; i < n; ++i) {
    cin >> r[i];
  }

  int ans = INT_MAX;
  for (int i = 0; i < n; ++i) {
    int cur = 0;
    for (int j = 0; j < n; ++j) {
      if (j >= i) {
        cur += r[j] * (j - i);
      } else {
        cur += r[j] * (n - i + j);
      }
    }
    ans = min(ans, cur);
  }
  cout << ans;
}
