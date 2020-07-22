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

  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    unordered_set<int> a;
    for (int i = 0; i < n; ++i) {
      int x;
      cin >> x;
      a.emplace(x);
    }

    int ans = -1;
    for (int i = 0; i < m; ++i) {
      int x;
      cin >> x;
      if (ans == -1 && a.count(x)) {
        ans = x;
      }
    }

    if (ans == -1) {
      cout << "NO\n";
    } else {
      cout << "YES\n1 " << ans << '\n';
    }
  }
}
