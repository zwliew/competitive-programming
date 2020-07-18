/*
ID: zhaowei10
TASK:
LANG: C++14
*/
#include "bits/stdc++.h"

using namespace std;

#ifdef LOCAL
#include "../../_library/cpp/debug.h"
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

  string s;
  cin >> s;
  for (int i = 0; i < (int)s.size();) {
    if (s[i] == '.') {
      cout << 0;
      ++i;
    } else if (i < (int)s.size() - 1) {
      if (s[i + 1] == '.') {
        cout << 1;
        i += 2;
      } else if (s[i + 1] == '-') {
        cout << 2;
        i += 2;
      }
    }
  }
}
