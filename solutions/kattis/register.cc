#include <bits/stdc++.h>
using namespace std;
#define debug(...) 0
#ifdef LOCAL
#include "../../_library/cc/debug.h"
#endif
// #define FILE "milkvisits"

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
#if defined(FILE) && !defined(LOCAL)
  freopen(FILE ".in", "r", stdin), freopen(FILE ".out", "w", stdout);
#endif

  const vector<int> mx = {2, 3, 5, 7, 11, 13, 17, 19};

  int ans = 0;
  int acc = 1;
  for (int i = 0; i < mx.size(); ++i) {
    int x;
    cin >> x;
    int cur = mx[i] - x - 1;
    ans += cur * acc;
    acc *= mx[i];
  }
  cout << ans;
}
