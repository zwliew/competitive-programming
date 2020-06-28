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

  int s, n;
  cin >> s >> n;
  vector<pair<int, int>> v(n);
  for (auto &[x, y] : v) {
    cin >> x >> y;
  }
  sort(v.begin(), v.end());

  for (int i = 0; i < n; ++i) {
    if (s <= v[i].first) {
      cout << "NO";
      return 0;
    }
    s += v[i].second;
  }
}