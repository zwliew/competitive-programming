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

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    int first = n;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      if (a[i] > 1 && first == n) {
        first = i;
      }
    }

    if ((first == n && n % 2) || (first < n && first % 2 == 0)) {
      cout << "First\n";
    } else {
      cout << "Second\n";
    }
  }
}
