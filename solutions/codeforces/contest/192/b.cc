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

  int n;
  cin >> n;
  vector<int> a(n);
  for (auto& x : a)
    cin >> x;

  int cmax = min(a[0], a[n - 1]);
  for (int i = 0; i < n - 1;) {
    if (i < n - 2 && a[i + 2] >= a[i + 1]) {
      cmax = min(cmax, a[i + 2]);
      i += 2;
    } else {
      cmax = min(cmax, a[i + 1]);
      ++i;
    }
  }
  cout << cmax;
}
