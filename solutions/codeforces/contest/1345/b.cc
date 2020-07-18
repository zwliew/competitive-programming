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

  int t;
  cin >> t;
  while (t--) {
    ll n;
    cin >> n;
    int cnt = 0;
    // f(n) = 2(1 + 2 + 3 + ... + n) + (0 + 1 + 2 + 3 + ... + (h - 1))
    //      = 3/2 * h^2 + h/2
    // Instead of binary search, 2 other options are possible:
    // Quadratic formula in O(1) time
    // Brute force in O(sqrt(n)) time
    while (n > 1) {
      ll lo = 1, hi = n, ans = 1;
      while (lo <= hi) {
        ll mid = lo + (hi - lo) / 2;
        if (mid * (3 * mid + 1) <= n * 2) {
          ans = mid;
          lo = mid + 1;
        } else {
          hi = mid - 1;
        }
      }
      n -= ans * (3 * ans + 1) / 2;
      ++cnt;
    }
    cout << cnt << '\n';
  }
}
