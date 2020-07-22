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

  int n, m;
  cin >> n;
  vector<int> a(n);
  for (auto& x : a)
    cin >> x;
  cin >> m;
  vector<int> b(m);
  for (auto& x : b)
    cin >> x;

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  int pairs = 0;
  int j = 0;
  for (int i = 0; i < n; ++i) {
    while (j < m && b[j] < a[i] - 1) {
      ++j;
    }
    if (j >= m)
      break;
    if (b[j] > a[i] + 1) {
      continue;
    }
    ++pairs;
    ++j;
  }
  cout << pairs;
}
