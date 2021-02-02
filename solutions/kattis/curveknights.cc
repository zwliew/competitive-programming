#include <bits/stdc++.h>
using namespace std;
#define debug(...) 0
#ifdef LOCAL
#include "../../_library/cc/debug.h"
#endif

void topoSort(vector<vector<array<int, 2>>>& adj,
              vector<int>& order,
              vector<bool>& vis,
              int u) {
  vis[u] = true;
  for (auto& [v, _] : adj[u]) {
    if (!vis[v]) {
      topoSort(adj, order, vis, v);
    }
  }
  order.push_back(u);
}

void compute(vector<vector<array<int, 2>>>& adj,
             vector<bool>& vis,
             vector<int64_t>& needed,
             int u) {
  if (vis[u])
    return;
  vis[u] = true;
  for (auto& [v, w] : adj[u]) {
    compute(adj, vis, needed, v);
    needed[u] += w * needed[v];
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
#if defined(FILE) && !defined(LOCAL)
  freopen(FILE ".in", "r", stdin), freopen(FILE ".out", "w", stdout);
#endif

  int N, M;
  cin >> N >> M;
  vector<int64_t> needed(N);
  for (auto& x : needed)
    cin >> x;

  vector<vector<array<int, 2>>> adj(N);
  for (int i = 0; i < M; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back({v, w});
  }

  vector<int> order;
  vector<bool> vis(N);
  for (int i = 0; i < N; ++i) {
    if (!vis[i]) {
      topoSort(adj, order, vis, i);
    }
  }
  reverse(order.begin(), order.end());

  vis.assign(N, false);
  for (int u : order) {
    compute(adj, vis, needed, u);
  }

  for (auto x : needed)
    cout << x << " ";
}
