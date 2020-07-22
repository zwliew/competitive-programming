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

  int m;
  cin >> m;
  vector<vector<bool>> adj(6, vector<bool>(6));
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u][v] = true;
    adj[v][u] = true;
  }

  auto know = [&](int i, int j) { return adj[i][j]; };

  for (int i = 1; i <= 5; ++i) {
    for (int j = i + 1; j <= 5; ++j) {
      for (int k = j + 1; k <= 5; ++k) {
        if (!know(i, j) && !know(i, k) && !know(j, k)) {
          cout << "WIN";
          return 0;
        }
        if (know(i, j) && know(i, k) && know(j, k)) {
          cout << "WIN";
          return 0;
        }
      }
    }
  }
  cout << "FAIL";
}
