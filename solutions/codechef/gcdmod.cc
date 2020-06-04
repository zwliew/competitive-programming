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

inline ll modpow(ll a, ll b, ll m) {
  ll ans = 1;
  while (b) {
    if (b & 1)
      ans = ((__int128)ans * a) % m;
    a = ((__int128)a * a) % m;
    b >>= 1;
  }
  return ans;
}

inline ll gcd(ll a, ll b) {
  while (b) {
    a %= b;
    swap(a, b);
  }
  return a;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(9);

#ifdef LOCAL
  freopen("test.in", "r", stdin);
  freopen("test.out", "w", stdout);
#else
#endif

  int t;
  cin >> t;
  const ll m = 1e9 + 7;
  while (t--) {
    ll a, b, n;
    cin >> a >> b >> n;
    cout << gcd(modpow(a, n, a == b ? m : a - b) +
                    modpow(b, n, a == b ? m : a - b),
                a - b) %
                m
         << '\n';
  }
}
