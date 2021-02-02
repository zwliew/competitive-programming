#include <bits/stdc++.h>
using namespace std;
#define debug(...) 0
#ifdef LOCAL
#include "../../_library/cc/debug.h"
#endif

void dfs(vector<vector<int>>& adj, vector<int>& col, int u, int c) {
  col[u] = c;
  for (int v : adj[u]) {
    if (!col[v])
      dfs(adj, col, v, c == 1 ? 2 : 1);
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
#if defined(FILE) && !defined(LOCAL)
  freopen(FILE ".in", "r", stdin), freopen(FILE ".out", "w", stdout);
#endif

  int N;
  cin >> N;
  vector<array<int, 2>> edges(N - 1);
  vector<vector<int>> adj(N);
  for (int i = 0; i < N - 1; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    edges[i] = {u, v};
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<int> col(N);
  dfs(adj, col, 0, 0);

  for (auto& [u, v] : edges) {
    cout << (int)(col[u] == 1) << "\n";
  }
}
