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

const int sz = 2e7;
bitset<sz + 1> primes;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(9);

#ifdef LOCAL
  freopen("test.in", "r", stdin);
  freopen("test.out", "w", stdout);
#else
#endif

  primes.set();
  primes[0] = primes[1] = 0;
  for (ll i = 2; i * i <= sz; ++i) {
    if (primes[i]) {
      for (ll j = i * i; j <= sz; j += i) {
        primes[j] = 0;
      }
    }
  }

  vi ans(100001);
  int cnt = 1;
  int prev = 2;
  for (int i = 3; i <= sz; i += 2) {
    if (primes[i]) {
      if (i - prev == 2) {
        ans[cnt] = prev;
        ++cnt;
        if (cnt > 100000) break;
      }
      prev = i;
    }
  }

  int x;
  while (cin >> x) {
    cout << '(' << ans[x] << ", " << ans[x] + 2 << ")\n";
  }
}
