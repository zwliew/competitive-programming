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
#define FILE "angry"
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int n, k;
  cin >> n >> k;
  if (n <= k) {
    cout << 0;
    return 0;
  }

  vector<int> pos(n);
  for (auto& x : pos)
    cin >> x;
  sort(pos.begin(), pos.end());

  int l = 0, r = 1e9;
  while (l < r - 1) {
    int m = l + (r - l) / 2;
    int ck = 0;
    for (int i = 0; i < n;) {
      int j = i;
      while (j < n && pos[j] - pos[i] <= m * 2)
        ++j;
      ++ck;
      i = j;
    }

    if (ck <= k) {
      r = m;
    } else {
      l = m;
    }
  }

  cout << r;
}
