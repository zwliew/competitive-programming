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

  ll a, b;
  cin >> a >> b;
  ll at = 0, bt = 0;
  ll pw = 1;
  while (a) {
    at = (a % 3) * pw + at;
    pw *= 10;
    a /= 3;
  }

  pw = 1;
  while (b) {
    bt = (b % 3) * pw + bt;
    b /= 3;
    pw *= 10;
  }

  ll anst = 0;
  pw = 1;
  while (at || bt) {
    ll c = ((bt % 10) - (at % 10) + 3) % 3;
    anst = c * pw + anst;
    pw *= 10;
    at /= 10;
    bt /= 10;
  }

  pw = 1;
  ll ans = 0;
  while (anst) {
    ans += (anst % 10) * pw;
    pw *= 3;
    anst /= 10;
  }

  cout << ans;
}
