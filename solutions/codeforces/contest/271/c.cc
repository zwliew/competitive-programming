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

  int n, k;
  cin >> n >> k;

  if (n < k * 3) {
    cout << -1;
    return 0;
  }

  for (int i = 0; i < k; ++i) {
    cout << i + 1 << ' ' << i + 1 << ' ';
  }

  for (int i = k * 2; i < k * 2 + k; ++i) {
    cout << i - k * 2 + 1 << ' ';
  }

  for (int i = k * 2 + k; i < n; ++i) {
    cout << k << ' ';
  }
}
