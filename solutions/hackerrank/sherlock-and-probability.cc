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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vi onePrefixCnt = {0};
    for (char c : s) {
      onePrefixCnt.eb(onePrefixCnt.back() + (c == '1'));
    }

    ll numerator = 0;
    for (int i = 0; i < (int)s.size(); ++i) {
      if (s[i] == '1') {
        numerator +=
            (ll)onePrefixCnt[min(n, i + k + 1)] - onePrefixCnt[max(0, i - k)];
      }
    }

    ll denominator = (ll)n * n;
    ll cd = __gcd(numerator, denominator);
    numerator /= cd;
    denominator /= cd;

    cout << numerator << '/' << denominator << '\n';
  }
}
