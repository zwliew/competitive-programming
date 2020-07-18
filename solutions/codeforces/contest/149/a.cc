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

  int n;
  cin >> n;
  vector<int> a(12);
  for (int& x : a)
    cin >> x;
  sort(a.rbegin(), a.rend());
  int cur = 0;
  int i;
  for (i = 0; i < 12 && cur < n; ++i) {
    cur += a[i];
  }
  cout << (cur < n ? -1 : i);
}
