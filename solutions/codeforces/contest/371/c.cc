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

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(9);

#ifdef LOCAL
  freopen("test.in", "r", stdin);
  freopen("test.out", "w", stdout);
#else
#endif

  // Simple binary search for the max number of burgers
  // Beware of overflow
  unordered_map<char, int> nti = {{'B', 0}, {'S', 1}, {'C', 2}};
  string ns;
  cin >> ns;
  vi needed(3);
  for (char c : ns) {
    needed[nti[c]]++;
  }

  int b, s, c;
  cin >> b >> s >> c;
  int pb, ps, pc;
  cin >> pb >> ps >> pc;
  ll r;
  cin >> r;

  ll lo = 0, hi = 1e14;
  ll ans = 0;
  while (lo <= hi) {
    ll mid = lo + (hi - lo) / 2;
    ll cost = max(0ll, needed[0] * mid - b) * pb +
              max(0ll, needed[1] * mid - s) * ps +
              max(0ll, needed[2] * mid - c) * pc;
    if (cost <= r) {
      ans = mid;
      lo = mid + 1;
    } else {
      hi = mid - 1;
    }
  }

  cout << ans;
}
