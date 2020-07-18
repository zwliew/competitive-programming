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
    int n, m;
    cin >> n >> m;
    vector<string> s;
    for (int i = 0; i < n; ++i) {
      string x;
      cin >> x;
      s.eb(x);
    }

    bool ok = false;
    for (int i = 0; i < m && !ok; ++i) {
      char orig = s[0][i];
      for (char c = 'a'; c <= 'z' && !ok; ++c) {
        s[0][i] = c;
        ok = true;
        for (int j = 1; j < n && ok; ++j) {
          int cnt = 0;
          for (int k = 0; k < m; ++k) {
            if (s[j][k] != s[0][k]) {
              ++cnt;
            }
          }
          if (cnt > 1) {
            ok = false;
          }
        }
        if (ok) {
          cout << s[0] << '\n';
          break;
        }
      }
      s[0][i] = orig;
    }

    if (!ok) {
      cout << -1 << '\n';
    }
  }
}
