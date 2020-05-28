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

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<vb> grid(n, vb(n));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        char c;
        cin >> c;
        grid[i][j] = c == '1';
      }
    }

    bool ok = true;
    for (int i = 0; i < n && ok; ++i) {
      for (int j = 0; j < n && ok; ++j) {
        ok = !grid[i][j] || i == n - 1 || j == n - 1 || grid[i][j + 1] ||
             grid[i + 1][j];
      }
    }

    if (ok)
      cout << "yes\n";
    else
      cout << "no\n";
  }
}
