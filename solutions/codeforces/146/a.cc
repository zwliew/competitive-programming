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

  int n;
  string s;
  cin >> n >> s;

  for (char c : s) {
    if (c != '4' && c != '7') {
      cout << "NO";
      return 0;
    }
  }

  int fours = 0;
  for (int i = 0; i < n / 2; ++i) {
    if (s[i] == '4') ++fours;
  }

  for (int i = n / 2; i < n; ++i) {
    if (s[i] == '4') --fours;
  }

  if (fours) {
    cout << "NO";
  } else {
    cout << "YES";
  }
}
