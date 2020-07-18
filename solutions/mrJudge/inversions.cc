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

int mergeSort(vector<int>& a, int l, int r) {
  if (l >= r) {
    return 0;
  }
  int m = l + (r - l) / 2;
  int f = mergeSort(a, l, m);
  int s = mergeSort(a, m + 1, r);
  vector<int> next;
  int i = l, j = m + 1;
  int ans = f + s;
  while (i <= m && j <= r) {
    if (a[i] <= a[j]) {
      next.emplace_back(a[i]);
      ++i;
    } else {
      next.emplace_back(a[j]);
      ++j;
      ans += m - i + 1;
    }
  }
  while (i <= m) {
    next.emplace_back(a[i]);
    ++i;
  }
  while (j <= r) {
    next.emplace_back(a[j]);
    ++j;
  }
  copy(next.begin(), next.end(), a.begin() + l);
  return ans;
}

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
    for (auto& x : a)
      cin >> x;

    cout << mergeSort(a, 0, n - 1) << '\n';
  }
}
