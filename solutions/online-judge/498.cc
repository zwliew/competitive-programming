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

  string first, second;
  while (getline(cin, first) && getline(cin, second)) {
    stringstream ss(first);
    int x;
    vi coeff;
    while (ss >> x) {
      coeff.eb(x);
    }
    ss = stringstream(second);
    bool seen = true;
    while (ss >> x) {
      int n = (int)coeff.size() - 1;
      int sum = 0;
      for (int i = 0; i <= n; ++i) {
        sum += power(x, n - i) * coeff[i];
      }
      if (!seen) {
        cout << ' ';
      } else {
        seen = false;
      }
      cout << sum;
    }
    cout << '\n';
  }
}
