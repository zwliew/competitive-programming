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

struct Edge {
  int u;
  int v;
  int w;

  Edge(int a, int b, int c) : u(a), v(b), w(c) {}
};

void dfs(vector<vector<int>>& adj,
         vector<Edge>& edges,
         vector<bool>& vis,
         int u) {
  vis[u] = true;
  for (int x : adj[u]) {
    auto& e = edges[x];
    if (!vis[e.v]) {
      dfs(adj, edges, vis, e.v);
    }
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int n, m;
  cin >> n >> m;
  vector<Edge> edges;
  vector<vector<int>> adj(n);
  for (int i = 0; i < m; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    edges.emplace_back(u - 1, v - 1, w);
    adj[u - 1].emplace_back(i);
  }

  vector<int64_t> dist(n, numeric_limits<int64_t>::min());
  dist[0] = 0;
  for (int i = 0; i < n - 1; ++i) {
    for (auto& e : edges) {
      if (dist[e.u] > numeric_limits<int64_t>::min() &&
          dist[e.v] < dist[e.u] + e.w) {
        dist[e.v] = dist[e.u] + e.w;
      }
    }
  }

  unordered_set<int> marked;
  for (auto& e : edges) {
    if (dist[e.u] > numeric_limits<int64_t>::min() &&
        dist[e.v] < dist[e.u] + e.w) {
      marked.emplace(e.v);
    }
  }

  vector<bool> vis(n);
  for (auto u : marked) {
    if (!vis[u]) {
      dfs(adj, edges, vis, u);
    }
  }

  if (vis[n - 1]) {
    cout << -1;
  } else {
    cout << dist[n - 1];
  }
}
