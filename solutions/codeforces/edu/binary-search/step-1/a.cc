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
#define FILE "balancing"
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
  for (auto& x : a)
    cin >> x;

  while (k--) {
    int x;
    cin >> x;

    int lo = 0, hi = n - 1;
    while (lo < hi) {
      int m = lo + (hi - lo) / 2;
      if (a[m] >= x) {
        hi = m;
      } else {
        lo = m + 1;
      }
    }
    cout << (a[hi] == x ? "YES" : "NO") << " ";

    // Alternative binary search implementation
    // int l = -1, r = n;
    // while (l < r - 1) {
    //   int m = l + (r - l) / 2;
    //   if (a[m] < x) {
    //     l = m;
    //   } else {
    //     r = m;
    //   }
    // }
    // cout << (r < n && a[r] == x ? "YES" : "NO") << '\n';

    // Straightforward solution using STL lower_bound()
    // cout << (*lower_bound(a.begin(), a.end(), x) == x ? "YES" : "NO") << " ";
  }
}
