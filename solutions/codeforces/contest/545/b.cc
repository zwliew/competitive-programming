/*
ID: zhaowei10
TASK:
LANG: C++14
*/
#include "bits/stdc++.h"

using namespace std;

#ifdef LOCAL
#include "../../_library/cc/debug.h"
#define FILE "test"
#else
#define debug(...) 0
#define FILE ""
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  string s, t;
  cin >> s >> t;

  int diff = 0;
  for (int i = 0; i < s.size(); ++i) {
    diff += s[i] != t[i];
  }

  if (diff % 2) {
    cout << "impossible";
    return 0;
  }

  int a = diff / 2, b = diff / 2;
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] != t[i]) {
      if (a) {
        cout << s[i];
        --a;
      } else {
        cout << t[i];
        --b;
      }
    } else {
      cout << s[i];
    }
  }
}
