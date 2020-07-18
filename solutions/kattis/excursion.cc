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

int64_t mergeSort(vector<char>& a, int l, int r) {
  if (l >= r) {
    return 0;
  }
  int m = l + (r - l) / 2;
  auto f = mergeSort(a, l, m);
  auto s = mergeSort(a, m + 1, r);
  vector<char> next;
  int i = l, j = m + 1;
  auto ans = f + s;
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
  vector<char> s;
  char c;
  while (cin >> c)
    s.emplace_back(c);
  cout << mergeSort(s, 0, s.size() - 1);
}
