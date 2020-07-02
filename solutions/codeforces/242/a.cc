/*
ID: zhaowei10
TASK:
LANG: C++14
*/
#include "bits/stdc++.h"

using namespace std;

#ifdef LOCAL
#include "../../_library/cpp/debug.h"
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

  int x, y, a, b;
  cin >> x >> y >> a >> b;
  vector<pair<int, int>> ans;
  for (int i = a; i <= x; ++i) {
    for (int j = b; j <= min(i - 1, y); ++j) {
      ans.emplace_back(i, j);
    }
  }

  cout << ans.size() << '\n';
  for (auto &[c, d] : ans) {
    cout << c << ' ' << d << '\n';
  }
}
