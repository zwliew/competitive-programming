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
  vector<int> v(n);
  for (auto &x : v) cin >> x;
  sort(v.begin(), v.end());

  int64_t sum = 0;
  for (int i = 0; i < n; ++i) {
    sum += abs(v[i] - i - 1);
  }
  cout << sum;
}
