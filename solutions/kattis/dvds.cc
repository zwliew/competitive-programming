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

  int k;
  cin >> k;
  while (k--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x : a)
      cin >> x;

    int cur = 1;
    for (int i = 0; i < n; ++i) {
      if (a[i] == cur) {
        ++cur;
      }
    }

    cout << n - cur + 1 << '\n';
  }
}
