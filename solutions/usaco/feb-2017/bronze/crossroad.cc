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
#define FILE "crossroad"
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int n;
  cin >> n;
  array<int, 11> pos;
  fill(pos.begin(), pos.end(), -1);

  int ans = 0;
  while (n--) {
    int i, x;
    cin >> i >> x;
    if (pos[i] != -1 && pos[i] != x) {
      ++ans;
    }
    pos[i] = x;
  }
  cout << ans;
}
