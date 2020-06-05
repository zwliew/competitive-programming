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

ll n, a, b;
inline ll next(ll x) { return ((((a * x) % n) * x) % n + b) % n; }

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(9);

#ifdef LOCAL
  freopen("test.in", "r", stdin);
  freopen("test.out", "w", stdout);
#else
#endif

  while (cin >> n && n) {
    cin >> a >> b;

    // Floyd's cycle-finding solution
    ll tortoise = next(0);
    ll hare = next(next(0));
    while (tortoise != hare) {
      tortoise = next(tortoise);
      hare = next(next(hare));
    }

    ll lam = 1;
    hare = next(tortoise);
    while (tortoise != hare) {
      hare = next(hare);
      ++lam;
    }

    cout << n - lam << '\n';

    // Simulation solution
    // ll cur = 0;
    // unordered_map<ll, int> cnt;
    // ll ans = n;
    // while (cnt[cur] < 2) {
    //   cnt[cur]++;
    //   if (cnt[cur] == 2) {
    //     --ans;
    //   }
    //   cur = (((a * cur) % n * cur) % n + b) % n;
    // }
    // cout << ans << '\n';
  }
}
