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

  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int &x : a) {
    cin >> x;
  }

  bool ok = true;
  for (int i = k - 1; i < n - 1; ++i) {
    if (a[i] != a[i + 1]) {
      ok = false;
      break;
    }
  }

  int first = 0;
  for (int i = k - 1; i >= 0; --i) {
    if (a[i] != a[k - 1]) {
      first = i + 1;
      break;
    }
  }

  if (ok) {
    cout << min(first, k - 1);
  } else {
    cout << -1;
  }
}
