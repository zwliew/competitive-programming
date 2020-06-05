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

  string s, t;
  cin >> s >> t;
  int yays = 0, whoops = 0;

  // Editorial solution
  vector<vi> count(2, vi(26));
  for (char c : t) {
    count[isupper(c)][tolower(c) - 'a']++;
  }

  vb counted(s.size());
  for (int i = 0; i < (int)s.size(); ++i) {
    char c = s[i];
    if (count[isupper(c)][tolower(c) - 'a']) {
      ++yays;
      --count[isupper(c)][tolower(c) - 'a'];
      counted[i] = 1;
    }
  }
  for (int i = 0; i < (int)s.size(); ++i) {
    char c = s[i];
    if (!counted[i] && count[!isupper(c)][tolower(c) - 'a']) {
      ++whoops;
      --count[!isupper(c)][tolower(c) - 'a'];
    }
  }

  // My original solution
  // vi upper(26), lower(26);
  // for (char c : t) {
  //   if (isupper(c)) {
  //     upper[c - 'A']++;
  //   } else {
  //     lower[c - 'a']++;
  //   }
  // }
  // vi supper(26), slower(26);
  // for (char c : s) {
  //   if (isupper(c)) {
  //     supper[c - 'A']++;
  //   } else {
  //     slower[c - 'a']++;
  //   }
  // }
  // for (int i = 0; i < 26; ++i) {
  //   int cupper = min(upper[i], supper[i]);
  //   int clower = min(lower[i], slower[i]);
  //   yays += cupper + clower;
  //   int total =
  //       min(upper[i] + lower[i], supper[i] + slower[i]) - cupper - clower;
  //   whoops += total;
  // }

  cout << yays << ' ' << whoops;
}
