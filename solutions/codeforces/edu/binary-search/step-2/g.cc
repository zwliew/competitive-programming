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

  int k, n;
  cin >> k >> n;
  vector<int> a(n);
  for (auto& x : a)
    cin >> x;

  int64_t l = 1, r = 1e16;
  while (l < r - 1) {
    int64_t m = l + (r - l) / 2;
    int64_t students = m * k;
    for (int x : a) {
      students -= min((int64_t)x, m);
    }
    if (students <= 0) {
      l = m;
    } else {
      r = m;
    }
  }
  cout << l;
}
