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

  string s;
  cin >> s;
  const ll mod = 1e9 + 7;
  ll cnt = 1;
  for (char c : s) {
    int val = 0;
    if (c >= '0' && c <= '9') {
      val = c - '0';
    } else if (c >= 'A' && c <= 'Z') {
      val = c - 'A' + 10;
    } else if (c >= 'a' && c <= 'z') {
      val = c - 'a' + 36;
    } else if (c == '-') {
      val = 62;
    } else if (c == '_') {
      val = 63;
    }

    for (int i = 0; i < 6; ++i) {
      if (!(val & 1)) {
        cnt *= 3;
        cnt %= mod;
      }
      val >>= 1;
    }
  }
  cout << cnt;
}
