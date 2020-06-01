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
using pi = pair<int, int>;
using vi = vector<int>;
using vpi = vector<pi>;
using vc = vector<char>;
using vb = vector<bool>;
using vll = vector<ll>;

ll lcm(ll a, ll b) { return a * b / __gcd(a, b); }
int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(9);

#ifdef LOCAL
  freopen("test.in", "r", stdin);
  freopen("test.out", "w", stdout);
#else
#endif

  ll n, m;
  while (cin >> n >> m) {
    vi arr(m);
    for (auto &x : arr) cin >> x;

    ll ans = 0;
    for (ll i = 0; i < (1 << m); ++i) {
      ll clcm = 1;
      ll bit_cnt = 0;
      for (ll j = 0; j < m; ++j) {
        if (i & (1 << j)) {
          ++bit_cnt;
          clcm = lcm(clcm, arr[j]);
        }
      }
      if (bit_cnt % 2) {
        ans -= n / clcm;
      } else {
        ans += n / clcm;
      }
    }
    cout << ans << '\n';
  }
}
