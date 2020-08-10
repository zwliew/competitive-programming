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
#define FILE "whereami"
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int n;
  string s;
  cin >> n >> s;

  for (int k = 1; k <= n; ++k) {
    unordered_set<string> seen;
    bool ok = true;
    for (int i = 0; i + k <= n; ++i) {
      string cur = s.substr(i, k);
      if (seen.count(cur)) {
        ok = false;
        break;
      }
      seen.emplace(cur);
    }

    if (ok) {
      cout << k;
      return 0;
    }
  }
}
