/*
ID: zhaowei10
TASK:
LANG: C++14
*/
#include <ext/numeric>
#include "bits/stdc++.h"

using namespace std;

#ifdef LOCAL
#include "../../_library/cc/debug.h"
#define FILE "test"
#else
#define debug(...) 0
#define FILE "balancing"
#endif

int backtrack(string n) {
  int ni = stoi(n);
  if (__gnu_cxx::power((int)sqrt(ni), 2) == ni) {
    return 0;
  }

  if (n.size() == 1) {
    return 1e9;
  }

  int best = 1e9;
  for (int i = 0; i < n.size(); ++i) {
    if (!i && i + 1 < n.size() && n[1] == '0')
      continue;
    string cur = n.substr(0, i) + n.substr(i + 1);
    best = min(best, backtrack(cur));
  }
  return best + 1;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  string n;
  cin >> n;
  int ans = backtrack(n);
  cout << (ans >= 1e9 ? -1 : ans);
}
