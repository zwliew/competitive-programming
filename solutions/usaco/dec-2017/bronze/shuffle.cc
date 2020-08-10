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
#define FILE "shuffle"
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
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    --x;
    a[x] = i;
  }
  vector<int> cur(n);
  for (auto& x : cur)
    cin >> x;

  for (int i = 0; i < 3; ++i) {
    vector<int> nxt(n);
    for (int j = 0; j < n; ++j) {
      nxt[a[j]] = cur[j];
    }
    cur = nxt;
  }

  for (auto x : cur) {
    cout << x << '\n';
  }
}
