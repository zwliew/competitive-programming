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

  const long long MOD = 1e9 + 7;
  long long x, y, n;
  cin >> x >> y >> n;
  vector<long long> ans = {x, y, y - x, -x, -y, x - y};
  n = (n + 5) % 6;
  long long cur = ans[n];
  while (cur < MOD) {
    cur += MOD;
  }
  cout << cur % MOD;
}
