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
#define FILE "lifeguards"
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int n;
  cin >> n;
  vector<int> covered(1001);
  vector<array<int, 2>> t(n);
  int cur = 0;
  for (int i = 0; i < n; ++i) {
    cin >> t[i][0] >> t[i][1];
    for (int j = t[i][0]; j < t[i][1]; ++j) {
      if (!covered[j]) {
        ++cur;
      }
      ++covered[j];
    }
  }

  int best = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = t[i][0]; j < t[i][1]; ++j) {
      --covered[j];
      if (!covered[j]) {
        --cur;
      }
    }
    best = max(best, cur);
    for (int j = t[i][0]; j < t[i][1]; ++j) {
      if (!covered[j]) {
        ++cur;
      }
      ++covered[j];
    }
  }
  cout << best;
}
