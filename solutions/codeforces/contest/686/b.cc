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

  while (n > 1) {
    int nextn = 0;
    for (int j = 0; j < n - 1; ++j) {
      if (a[j] > a[j + 1]) {
        swap(a[j], a[j + 1]);
        cout << j + 1 << ' ' << j + 2 << '\n';
        nextn = j + 1;
      }
    }
    n = nextn;
  }

  debug(a);
}
