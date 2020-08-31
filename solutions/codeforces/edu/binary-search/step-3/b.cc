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

  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (auto& x : a)
    cin >> x;

  int64_t l = 0, r = 1e14;
  while (l < r - 1) {
    auto m = l + (r - l) / 2;
    int curK = 0;
    int64_t curSum = m;
    for (int i = 0; i < n; ++i) {
      if (a[i] > m) {
        curK = k + 1;
        break;
      }
      curSum += a[i];
      if (curSum > m) {
        ++curK;
        curSum = a[i];
      }
    }

    if (curK <= k) {
      r = m;
    } else {
      l = m;
    }
  }

  cout << r;
}
