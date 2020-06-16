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

  int n, m, q;
  cin >> n >> m >> q;
  vector<vector<long long>> dist(n + 1, vector<long long>(n + 1, 1e18));
  while (m--) {
    long long u, v, w;
    cin >> u >> v >> w;
    // Beware of multiple edges
    dist[u][v] = min(dist[u][v], w);
    dist[v][u] = min(dist[v][u], w);
  }
  for (int i = 0; i <= n; ++i) {
    dist[i][i] = 0;
  }

  for (int k = 1; k <= n; ++k) {
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }

  while (q--) {
    int u, v;
    cin >> u >> v;
    if (dist[u][v] >= 1e18) {
      cout << -1;
    } else {
      cout << dist[u][v];
    }
    cout << '\n';
  }
}
