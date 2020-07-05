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

  int n;
  cin >> n;
  vector<int64_t> a(n);
  int64_t sum = 0;
  unordered_map<int64_t, vector<int>> hm;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    sum += a[i];
    if (i < n - 1)
      hm[sum].emplace_back(i);
  }

  if (sum % 3) {
    cout << 0;
    return 0;
  }

  sum /= 3;
  int64_t cur = 0;
  int64_t ans = 0;
  for (int i = 0; i < n; ++i) {
    cur += a[i];
    if (cur != sum)
      continue;
    auto &v = hm[cur + sum];
    auto it = upper_bound(v.begin(), v.end(), i);
    ans += distance(it, v.end());
  }
  cout << ans;
}

