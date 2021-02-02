#include <bits/stdc++.h>
using namespace std;
#define debug(...) 0
#ifdef LOCAL
#include "../../_library/cc/debug.h"
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
#if defined(FILE) && !defined(LOCAL)
  freopen(FILE ".in", "r", stdin), freopen(FILE ".out", "w", stdout);
#endif

  int K;
  cin >> K;
  int ans = 1;
  int prev = -1;
  for (int i = 0; i < K; ++i) {
    int cur;
    cin >> cur;
    if (cur < prev) {
      ++ans;
    }
    prev = cur;
  }
  cout << ans;
}
