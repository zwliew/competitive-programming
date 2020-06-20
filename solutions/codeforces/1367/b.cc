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

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    int odd = 0;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      if (a[i] % 2) ++odd;
      if (a[i] % 2 != i % 2) ++cnt;
    }

    if (odd != n / 2) {
      cout << "-1\n";
      continue;
    }

    cout << cnt / 2 << '\n';
  }
}
