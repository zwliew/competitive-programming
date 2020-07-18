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

int compute(vector<int>& a, int k, int i, int j) {
  if (k < 0) {
    return 1e9;
  }
  if (i >= j) {
    return 0;
  }

  if (a[i] == a[j]) {
    return compute(a, k, i + 1, j - 1);
  }
  return min(compute(a, k - 1, i + 1, j), compute(a, k - 1, i, j - 1)) + 1;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int t;
  cin >> t;
  for (int ti = 1; ti <= t; ++ti) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto& x : a)
      cin >> x;

    cout << "Case " << ti << ": ";
    int ans = compute(a, k, 0, n - 1);
    if (ans >= 1e9) {
      cout << "Too difficult";
    } else if (ans == 0) {
      cout << "Too easy";
    } else {
      cout << ans;
    }
    cout << '\n';
  }
}
