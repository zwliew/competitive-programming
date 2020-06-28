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

void toposort(vector<vector<int>> &adj, vector<int> &order, vector<bool> &vis,
              int u) {
  vis[u] = true;
  for (int v : adj[u]) {
    if (!vis[v]) {
      toposort(adj, order, vis, v);
    }
  }
  order.emplace_back(u);
}

void dfs(vector<vector<int>> &adj, vector<bool> &vis, vector<vector<int>> &sccs,
         int u) {
  vis[u] = true;
  sccs.back().emplace_back(u);
  for (int v : adj[u]) {
    if (!vis[v]) {
      dfs(adj, vis, sccs, v);
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
  vector<vector<int>> adj(n), adjt(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].emplace_back(v);
    adjt[v].emplace_back(u);
  }

  vector<bool> vis(n);
  vector<int> order;
  for (int i = 0; i < n; ++i) {
    if (!vis[i]) {
      toposort(adj, order, vis, i);
    }
  }

  vector<vector<int>> sccs;
  vis.assign(n, false);
  reverse(order.begin(), order.end());
  for (int u : order) {
    if (!vis[u]) {
      sccs.resize(sccs.size() + 1);
      dfs(adjt, vis, sccs, u);
    }
  }

  cout << sccs.size() << '\n';
  for (auto &v : sccs) {
    cout << v.size() << ' ';
    for (auto x : v) {
      cout << x << ' ';
    }
    cout << '\n';
  }
}
