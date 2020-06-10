/*
ID: zhaowei10
TASK:
LANG: C++14
*/
#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>

using namespace __gnu_cxx;
using namespace __gnu_pbds;
using namespace std;

#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 0
#endif

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << fixed;

#ifdef LOCAL
  freopen("test.in", "r", stdin);
  freopen("test.out", "w", stdout);
#else
#endif

  int n, d;
  cin >> n >> d;
  vector<int> points(n);
  for (auto &x : points) cin >> x;

  int j = 0;
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    while (j < n - 1 && points[j + 1] - points[i] <= d) {
      ++j;
    }
    ans += (long long)(j - i) * (j - i - 1) / 2;
  }
  cout << ans;
}
