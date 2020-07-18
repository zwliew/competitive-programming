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
  cin >> s;

  char best;
  int cnt = 0;
  for (char c : s) {
    if (c > best) {
      best = c;
      cnt = 1;
    } else if (c == best) {
      ++cnt;
    }
  }
  for (int i = 0; i < cnt; ++i) {
    cout << best;
  }

  // Brute force solution
  // string best;
  // for (int i = 0; i < (1 << s.size()); ++i) {
  //   string cur;
  //   for (int j = 0; j < s.size(); ++j) {
  //     if (i & (1 << j)) {
  //       cur += s[j];
  //     }
  //   }
  //   bool ok = true;
  //   for (int j = 0; j < cur.size() / 2; ++j) {
  //     if (cur[j] != cur[cur.size() - 1 - j]) {
  //       ok = false;
  //       break;
  //     }
  //   }
  //   if (ok) {
  //     best = max(best, cur);
  //   }
  // }
  // cout << best;
}
