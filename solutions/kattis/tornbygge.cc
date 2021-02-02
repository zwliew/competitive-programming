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

  int N;
  cin >> N;
  int prev = 0;
  int ans = 0;
  while (N--) {
    int cur;
    cin >> cur;
    if (cur > prev) {
      ++ans;
    }
    prev = cur;
  }
  cout << ans;
}
