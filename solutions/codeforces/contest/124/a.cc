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

  int n, a, b;
  cin >> n >> a >> b;

  // Mathematical solution
  cout << n - max(a + 1, n - b) + 1;

  // Brute force solution
  // int cnt = 0;
  // for (int x = a; x < n; ++x) {
  //   if (n - 1 - x <= b) {
  //     ++cnt;
  //   }
  // }
  // cout << cnt;
}
