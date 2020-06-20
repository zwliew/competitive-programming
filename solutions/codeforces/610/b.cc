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
  int maxVal = *max_element(a.begin(), a.end());
  int minVal = *min_element(a.begin(), a.end());

  if (minVal == maxVal) {
    cout << (long long)minVal * n;
    return 0;
  }

  int cur = 0;
  int left = n, right = -1;
  for (int i = 0; i < n; ++i) {
    if (a[i] == minVal) {
      cur = max(cur, i - right);
      right = i;
      if (left == n) {
        left = i;
      }
    }
  }

  cout << (long long)n * minVal - 1 + max(n - right + left, cur);
}
