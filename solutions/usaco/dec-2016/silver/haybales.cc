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
#define FILE "haybales"
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int n, q;
  cin >> n >> q;
  vector<int> pos(n);
  for (int i = 0; i < n; ++i) {
    cin >> pos[i];
  }
  sort(pos.begin(), pos.end());

  while (q--) {
    int l, r;
    cin >> l >> r;
    auto ub = upper_bound(pos.begin(), pos.end(), r);
    auto lb = lower_bound(pos.begin(), pos.end(), l);
    cout << ub - lb << '\n';
  }
}
