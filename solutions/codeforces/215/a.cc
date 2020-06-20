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
  for (auto &x : a) cin >> x;
  int m;
  cin >> m;
  vector<int> b(m);
  for (auto &x : b) cin >> x;

  int bestRatio = 0;
  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (b[j] % a[i] == 0) {
        if (b[j] / a[i] > bestRatio) {
          bestRatio = b[j] / a[i];
          cnt = 1;
        } else if (b[j] / a[i] == bestRatio) {
          ++cnt;
        }
      }
    }
  }

  cout << cnt;
}
