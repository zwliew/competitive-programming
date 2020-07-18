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

  int n, m;
  cin >> n >> m;
  vector<int> a(n), b(m);
  for (auto& x : a)
    cin >> x;
  for (auto& x : b)
    cin >> x;

  int i = 0;
  for (int j = 0; i < n && j < m; ++j) {
    if (b[j] >= a[i]) {
      ++i;
    }
  }
  cout << n - i;
}
