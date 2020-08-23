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

  int n;
  cin >> n;
  vector<int> a(n);
  for (auto& x : a)
    cin >> x;
  sort(a.begin(), a.end());

  int k;
  cin >> k;
  while (k--) {
    int l, r;
    cin >> l >> r;

    int lo = 0, hi = n - 1;
    while (lo < hi) {
      int m = lo + (hi - lo) / 2;
      if (a[m] > r) {
        hi = m;
      } else {
        lo = m + 1;
      }
    }

    r = hi + (a[hi] <= r);

    lo = 0;
    hi = n - 1;
    while (lo < hi) {
      int m = lo + (hi - lo) / 2;
      if (a[m] >= l) {
        hi = m;
      } else {
        lo = m + 1;
      }
    }
    l = hi + (a[hi] < l);

    cout << r - l << " ";

    // Alternative implementation
    // int lo = -1, hi = n;
    // while (lo < hi - 1) {
    //   int m = lo + (hi - lo) / 2;
    //   if (a[m] > r) {
    //     hi = m;
    //   } else {
    //     lo = m;
    //   }
    // }
    // r = hi;
    // lo = -1, hi = n;
    // while (lo < hi - 1) {
    //   int m = lo + (hi - lo) / 2;
    //   if (a[m] >= l) {
    //     hi = m;
    //   } else {
    //     lo = m;
    //   }
    // }
    // cout << r - hi << " ";

    // Simple solution using STL functions
    // cout << (upper_bound(a.begin(), a.end(), r) -
    //          lower_bound(a.begin(), a.end(), l))
    //      << " ";
  }
}
