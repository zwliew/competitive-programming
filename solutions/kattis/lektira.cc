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
  string ans = s;
  for (int i = 1; i <= (int)s.size(); ++i) {
    for (int j = i + 2; j < (int)s.size(); ++j) {
      string x = s;
      reverse(x.begin(), x.begin() + i);
      reverse(x.begin() + i, x.begin() + j);
      reverse(x.begin() + j, x.end());
      ans = min(ans, x);
    }
  }
  cout << ans;
}
