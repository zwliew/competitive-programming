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

#define f first
#define s second
#define eb emplace_back

using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using vi = vector<int>;
using vpi = vector<pi>;
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

  ll n, m, t;
  cin >> n >> m >> t;
  ll ans = 0;
  for (ll i = 4; i <= t - 1; ++i) {
    ll j = t - i;
    if (i < 4 || j < 1 || i > n || j > m)
      continue;

    vll num, denom;
    for (ll k = n; k > n - i; --k) {
      num.eb(k);
    }
    for (ll k = m; k > m - j; --k) {
      num.eb(k);
    }

    for (ll k = i; k > 1; --k) {
      ll cur = k;
      for (ll d = 2; d * d <= cur; ++d) {
        while (cur % d == 0) {
          denom.eb(d);
          cur /= d;
        }
      }
      if (cur > 1)
        denom.eb(cur);
    }
    for (ll k = j; k > 1; --k) {
      ll cur = k;
      for (ll d = 2; d * d <= n; ++d) {
        while (cur % d == 0) {
          denom.eb(d);
          cur /= d;
        }
      }
      if (cur > 1)
        denom.eb(cur);
    }

    for (ll denomi = 0; denomi < (ll)denom.size(); ++denomi) {
      for (ll numi = 0; numi < (ll)num.size(); ++numi) {
        if (num[numi] % denom[denomi] == 0) {
          num[numi] /= denom[denomi];
          denom[denomi] = 1;
          break;
        }
      }
    }

    ll cur = 1;
    for (ll x : num) {
      cur *= x;
    }
    ans += cur;
  }
  cout << ans;
}
