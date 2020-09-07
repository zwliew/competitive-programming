#include <vector>
struct LCA {
  std::vector<std::vector<int>> up, adj;
  std::vector<int> depth;
  int t = 0;

  LCA(int n) {
    int d = 1;
    while ((1 << d) < n)
      ++d;
    up.assign(d + 1, std::vector<int>(n));
    adj.resize(n);
    depth.resize(n);
  }

  void addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  void dfs(int u = 0) {
    for (int i = 1; i < up.size(); ++i) {
      up[i][u] = up[i - 1][up[i - 1][u]];
    }
    for (int v : adj[u]) {
      if (v != up[0][u]) {
        up[0][v] = u;
        depth[v] = depth[u] + 1;
        dfs(v);
      }
    }
  }

  int lca(int u, int v) {
    if (depth[u] < depth[v])
      std::swap(u, v);
    u = jump(u, depth[u] - depth[v]);
    if (u == v)
      return u;
    for (int i = up.size() - 1; i >= 0; --i) {
      if (up[i][u] != up[i][v]) {
        u = up[i][u];
        v = up[i][v];
      }
    }
    return up[0][u];
  }

  int jump(int u, int d) {
    for (int i = 0; i < up.size() && d; ++i, d >>= 1) {
      if (d & 1) {
        u = up[i][u];
      }
    }
    return u;
  }

  int dist(int u, int v) { return depth[u] + depth[v] - depth[lca(u, v)] * 2; }
};