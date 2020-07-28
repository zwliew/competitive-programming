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

  string s;
  cin >> s;
  int lastIdx = -1;
  for (int i = 0; i < s.size(); ++i) {
    if ((s[i] - '0') % 2 == 0) {
      lastIdx = i;
      if (s[i] < s.back()) {
        swap(s[i], s.back());
        cout << s;
        return 0;
      }
    }
  }
  if (lastIdx >= 0) {
    swap(s[lastIdx], s.back());
    cout << s;
    return 0;
  }

  cout << -1;
}
