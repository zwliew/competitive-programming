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

  int n, k;
  cin >> n >> k;
  vector<int> pos(n);
  for (auto& x : pos)
    cin >> x;

  int l = 1, r = 1e9 + 1;
  while (l < r - 1) {
    int m = l + (r - l) / 2;
    int prev = -1e9 - 1;
    int ck = 0;
    for (int i = 0; i < n; ++i) {
      if (pos[i] - prev >= m) {
        prev = pos[i];
        ++ck;
      }
    }

    if (ck >= k) {
      l = m;
    } else {
      r = m;
    }
  }

  cout << l;
}
