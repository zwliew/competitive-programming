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

ll mpow(ll a, ll b, ll m) {
  ll ans = 1;
  while (b) {
    if (b & 1) {
      ans = (ans * a) % m;
    }
    b >>= 1;
    a = (a * a) % m;
  }
  return ans;
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
  for (int ti = 1; ti <= t; ++ti) {
    int n;
    cin >> n;
    cout << "Case #" << ti << ": ";
    if (n <= 2) {
      cout << 1;
    } else {
      cout << mpow(n, n - 2, 2000000011);
    }
    cout << '\n';
  }
}
