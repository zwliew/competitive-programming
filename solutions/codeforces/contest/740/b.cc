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
  vector<int> a(n);
  for (auto& x : a)
    cin >> x;

  int sum = 0;
  while (m--) {
    int l, r;
    cin >> l >> r;
    --l;
    int cur = 0;
    for (int i = l; i < r; ++i) {
      cur += a[i];
    }
    sum += max(0, cur);
  }
  cout << sum;
}
