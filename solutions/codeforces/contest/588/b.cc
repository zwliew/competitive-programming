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

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(9);

#ifdef LOCAL
  freopen("test.in", "r", stdin);
  freopen("test.out", "w", stdout);
#else
#endif

  ll n;
  cin >> n;

  // Editorial solution
  // Find all prime divisors of N. The answer is the product of all
  // the prime divisors.
  ll ans = 1;
  for (ll i = 2; i * i <= n; ++i) {
    if (n % i == 0) {
      ans *= i;
      while (n % i == 0) {
        n /= i;
      }
    }
  }
  if (n) ans *= n;
  cout << ans;

  // Brute force solution - generate all squares in O(sqrt(N))
  // and iterate through all divisors in O(sqrt(N)) and determine divisibility.
  //   vll sqs;
  //   for (ll i = 2; i <= sqrt(n); ++i) {
  //     sqs.emplace_back(i * i);
  //   }

  //   ll ans = 1;
  //   for (ll i = 1; i <= sqrt(n); ++i) {
  //     if (n % i == 0) {
  //       ll j = n / i;
  //       bool ok = true;
  //       for (ll sq : sqs) {
  //         if (j % sq == 0) {
  //           ok = false;
  //           break;
  //         }
  //       }
  //       if (ok) {
  //         ans = max(ans, j);
  //       }

  //       ok = true;
  //       for (ll sq : sqs) {
  //         if (i % sq == 0) {
  //           ok = false;
  //           break;
  //         }
  //       }
  //       if (ok) {
  //         ans = max(ans, i);
  //       }
  //     }
  //   }

  //   cout << ans;
}
