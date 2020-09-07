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

void dfs(vector<vector<int>> &adj, vector<int> &dist, int u, int p = 0) {
  dist[u] = dist[p] + 1;
  for (auto v : adj[u]) {
    if (v == p) continue;
    dfs(adj, dist, v, u);
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int n;
  cin >> n;
  vector<vector<int>> adj(n + 1);
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
  }

  vector<int> dist(n + 1);
  dfs(adj, dist, 1);

  int furthest = max_element(dist.begin(), dist.end()) - dist.begin();
  dist = vector<int>(n + 1);
  dfs(adj, dist, furthest);

  cout << *max_element(dist.begin(), dist.end()) - 1;
}
