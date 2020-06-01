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

const int sz = 1e7;
bitset<sz + 1> p;
int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(9);

#ifdef LOCAL
  freopen("test.in", "r", stdin);
  freopen("test.out", "w", stdout);
#else
#endif

  p.set();
  p[0] = p[1] = 0;
  for (int i = 4; i <= sz; i += 2) {
    p[i] = 0;
  }
  for (ll i = 3; i * i <= sz; i += 2) {
    if (p[i]) {
      for (ll j = i * i; j <= sz; j += i) {
        p[j] = 0;
      }
    }
  }

  vi lastPrimes = {0, 1, 2};
  for (int i = 3; i <= sz; ++i) {
    if (p[i]) {
      lastPrimes.eb(i);
    } else {
      lastPrimes.eb(lastPrimes.back());
    }
  }

  int n;
  while (cin >> n) {
    if (n <= 7) {
      cout << "Impossible.\n";
    } else {
      for (int i = 3; i >= 0; --i) {
        cout << lastPrimes[n - i * 2] << ' ';
        n -= lastPrimes[n - i * 2];
      }
      cout << '\n';
    }
  }
}
