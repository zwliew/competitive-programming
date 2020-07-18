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
    ll a, b;
    cin >> a >> b;

    int cnt = 0;
    while (cnt < 100 && a != b) {
      if (a < b) {
        if (a * 8 <= b) {
          a *= 8;
        } else if (a * 4 <= b) {
          a *= 4;
        } else {
          a *= 2;
        }
      } else {
        if (a % 8 == 0 && a / 8 >= b) {
          a /= 8;
        } else if (a % 4 == 0 && a / 4 >= b) {
          a /= 4;
        } else if (a % 2 == 0) {
          a /= 2;
        }
      }
      ++cnt;
    }

    if (a != b) {
      cout << -1;
    } else {
      cout << cnt;
    }
    cout << '\n';
  }
}
