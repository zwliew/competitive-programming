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

  int k;
  cin >> k;
  k *= 2;
  vi count(10);
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      char c;
      cin >> c;
      if (c != '.') {
        c -= '0';
        count[c]++;
        if (count[c] > k) {
          cout << "NO";
          return 0;
        }
      }
    }
  }
  cout << "YES";
}
