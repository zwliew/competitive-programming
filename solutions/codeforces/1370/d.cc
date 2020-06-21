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
  for (auto &x : a) cin >> x;

  int lo = 1, hi = *max_element(a.begin(), a.end());
  int ans = hi;
  while (lo <= hi) {
    int mid = lo + (hi - lo) / 2;
    vector<int> len(2);
    for (int i = 0; i < n; ++i) {
      if (a[i] <= mid) {
        len[0]++;
        len[1]++;
      } else {
        if (len[0] % 2 == 0) {
          ++len[0];
        }
        if (len[1] % 2) {
          ++len[1];
        }
      }
    }
    if (len[0] >= k || len[1] >= k) {
      ans = mid;
      hi = mid - 1;
    } else {
      lo = mid + 1;
    }
  }
  cout << ans;
}
