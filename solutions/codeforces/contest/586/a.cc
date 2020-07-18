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
  vector<int> a(n);
  int first = -1, last = -1;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    if (a[i]) {
      last = i;
      if (first == -1) {
        first = i;
      }
    }
  }
  int ans = last - first + 1;
  if (first == -1) {
    cout << 0;
    return 0;
  }
  for (int i = first + 1; i < last; ++i) {
    if (!a[i]) {
      int j = i + 1;
      while (j < last && !a[j]) {
        ++j;
      }
      if (j - i > 1) {
        ans -= j - i;
      }
      i = j;
    }
  }
  cout << ans;
}
