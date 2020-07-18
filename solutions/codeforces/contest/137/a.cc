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
  int cur = 0;
  int ans = 0;
  char prev = 0;
  for (char c : s) {
    if (c != prev || cur == 5) {
      ++ans;
      cur = 0;
      prev = 0;
    }
    prev = c;
    ++cur;
  }
  cout << ans;
}
