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

  string t, p;
  cin >> t >> p;
  vector<int> a(t.size());
  for (auto& x : a) {
    cin >> x;
    --x;
  }

  int l = 0, r = t.size();
  while (l < r - 1) {
    int m = l + (r - l) / 2;
    vector<bool> del(t.size());
    for (int i = 0; i < m; ++i) {
      del[a[i]] = true;
    }

    int j = 0;
    for (int i = 0; j < p.size() && i < t.size(); ++i) {
      if (del[i])
        continue;
      if (t[i] == p[j]) {
        ++j;
      }
    }

    if (j == p.size()) {
      l = m;
    } else {
      r = m;
    }
  }

  cout << l;
}
