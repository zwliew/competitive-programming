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

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << fixed;

#ifdef LOCAL
  freopen("test.in", "r", stdin);
  freopen("test.out", "w", stdout);
#else
#endif

  int n, k;
  string s;
  cin >> n >> k >> s;

  int g = 0, t = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'G')
      g = i;
    else if (s[i] == 'T')
      t = i;
  }

  int i;
  for (i = g; i >= 0 && i < n && i != t && s[i] != '#'; i += (g < t ? k : -k))
    ;

  cout << (i == t ? "YES" : "NO");
}
