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

  int n;
  cin >> n;
  int cmin = 0;
  int cmax = 1000;
  while (n--) {
    int a, b;
    cin >> a >> b;
    cmin = max(cmin, a);
    cmax = min(cmax, b);
    if (cmin > cmax) {
      cout << "edward is right";
      return 0;
    }
  }
  cout << "gunilla has a point";
}
