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

  int sum, lim;
  cin >> sum >> lim;

  vi ans;
  for (int i = lim; i >= 1; --i) {
    int lowbit = 1 << __builtin_ctz(i);
    if (sum >= lowbit) {
      ans.eb(i);
      sum -= lowbit;
    }
  }

  if (sum) {
    cout << -1;
    return 0;
  }

  cout << ans.size() << '\n';
  for (auto x : ans) {
    cout << x << ' ';
  }
}
