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

  ll a, b;
  cin >> a >> b;

  // Official editorial solution
  int cd = gcd(a, b);
  a /= cd;
  b /= cd;
  if (abs(a - b) == 1) {
    cout << "Equal";
  } else if (a < b) {
    cout << "Dasha";
  } else {
    cout << "Masha";
  }

  // My original brute force solution
  // ll cm = lcm(a, b);
  // ll d = 0, m = 0;
  // for (ll i = 1; i <= cm;) {
  //   ll dceil = (i + a - 1) / a * a;
  //   ll mceil = (i + b - 1) / b * b;
  //   if (dceil > mceil) {
  //     m += mceil - i + 1;
  //   } else if (dceil < mceil) {
  //     d += dceil - i + 1;
  //   } else if (a < b) {
  //     m += mceil - i + 1;
  //   } else {
  //     d += dceil - i + 1;
  //   }
  //   i = min(mceil, dceil) + 1;
  // }

  // if (d == m) {
  //   cout << "Equal";
  // } else if (d < m) {
  //   cout << "Masha";
  // } else {
  //   cout << "Dasha";
  // }
}
