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
  reverse(s.begin(), s.end());

  int ans = 0;
  for (int i = 0; i < s.size() - 1; ++i) {
    ++ans;
    if (s[i] == '1') {
      int j = i;
      while (j < s.size() && s[j] == '1') {
        ++j;
      }
      ans += j - i;
      if (j == s.size()) {
        s += '1';
      } else {
        s[j] = '1';
      }
      i = j - 1;
    }
  }
  cout << ans;
}
