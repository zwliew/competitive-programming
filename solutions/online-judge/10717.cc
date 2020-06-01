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

inline ll lcm(ll a, ll b) {
  ll ap = a;
  ll ab = b;
  while (b) {
    a %= b;
    swap(a, b);
  }
  return ap / a * ab;
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

  int n, t;
  while (cin >> n >> t && (n || t)) {
    vll arr(n);
    for (auto &x : arr) {
      cin >> x;
    }

    unordered_set<ll> lcms;
    for (int i = 0; i < n - 3; ++i) {
      for (int j = i + 1; j < n - 2; ++j) {
        ll lcm2 = lcm(arr[i], arr[j]);
        for (int k = j + 1; k < n - 1; ++k) {
          ll lcm3 = lcm(lcm2, arr[k]);
          for (int l = k + 1; l < n; ++l) {
            ll lcm4 = lcm(lcm3, arr[l]);
            lcms.emplace(lcm4);
          }
        }
      }
    }

    while (t--) {
      ll x;
      cin >> x;
      ll under = 0, upper = 1e18;
      for (ll y : lcms) {
        under = max(under, x / y * y);
        upper = min(upper, (x + y - 1) / y * y);
      }
      cout << under << ' ' << upper << '\n';
    }
  }
}
