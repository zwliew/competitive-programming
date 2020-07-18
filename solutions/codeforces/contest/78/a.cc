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

  string s;
  vi needed = {5, 7, 5};
  vc vowels = {'a', 'e', 'i', 'o', 'u'};
  for (int i = 0; i < 3; ++i) {
    getline(cin, s);
    int cnt = 0;
    for (char c : s) {
      bool ok = false;
      for (char v : vowels) {
        if (c == v) {
          ok = true;
          break;
        }
      }
      if (ok) {
        cnt++;
      }
    }
    if (cnt != needed[i]) {
      cout << "NO";
      return 0;
    }
  }
  cout << "YES";
}
