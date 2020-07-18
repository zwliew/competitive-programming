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

  int64_t n, m;
  cin >> n >> m;
  unordered_set<int> cols, rows;
  while (m--) {
    int x, y;
    cin >> x >> y;
    cols.emplace(x);
    rows.emplace(y);
    int64_t total = (n - rows.size()) * (n - cols.size());
    cout << total << ' ';
  }
}
