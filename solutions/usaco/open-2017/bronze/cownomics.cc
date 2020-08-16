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
#define FILE "cownomics"
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int n, m;
  cin >> n >> m;
  vector<vector<string>> cows(2, vector<string>(n));
  for (int i = 0; i < n; ++i)
    cin >> cows[0][i];
  for (int i = 0; i < n; ++i)
    cin >> cows[1][i];

  int ans = 0;
  for (int i = 0; i < m; ++i) {
    unordered_set<char> seen;
    for (int j = 0; j < n; ++j) {
      seen.emplace(cows[0][j][i]);
    }
    bool ok = true;
    for (int j = 0; j < n; ++j) {
      if (seen.count(cows[1][j][i])) {
        ok = false;
        break;
      }
    }

    if (ok) {
      ++ans;
    }
  }
  cout << ans;
}
