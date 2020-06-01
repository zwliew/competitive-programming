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

#define eb emplace_back

using ll = long long;
using ld = long double;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;
using vc = vector<char>;
using vb = vector<bool>;
using vll = vector<ll>;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(9);

#ifdef LOCAL
  freopen("test.in", "r", stdin);
  freopen("test.out", "w", stdout);
#else
#endif

  // ll n;
  // cin >> n;
  // unordered_map<int, int> beauties;
  // int cmin = INT_MAX, cmax = INT_MIN;
  // vi flowers;
  // for (int i = 0; i < n; ++i) {
  //   int x;
  //   cin >> x;
  //   flowers.eb(x);
  //   beauties[flowers[i]]++;
  //   cmin = min(x, cmin);
  //   cmax = max(x, cmax);
  // }

  // ll ans = 0;
  // int delta = cmax - cmin;
  // if (delta == 0) {
  //   cout << delta << ' ' << n * (n - 1) / 2;
  //   return 0;
  // }

  // for (int i = 0; i < n; ++i) {
  //   ans += beauties[flowers[i] - delta];
  // }
  // cout << delta << ' ' << ans;

  // Better solution
  int n;
  cin >> n;
  int cmin = INT_MAX, cmax = INT_MIN;
  int mincnt = 0, maxcnt = 0;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    if (x < cmin) {
      cmin = x;
      mincnt = 0;
    }
    if (x > cmax) {
      cmax = x;
      maxcnt = 0;
    }
    mincnt += x == cmin;
    maxcnt += x == cmax;
  }

  if (cmax == cmin) {
    cout << "0 " << (ll) n * (n - 1) / 2;
    return 0;
  }

  cout << cmax - cmin << ' ' << (ll) mincnt * maxcnt;
}
