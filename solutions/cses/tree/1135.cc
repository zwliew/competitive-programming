#include <algorithm>
#include <array>
#include <bitset>
#include <chrono>
#include <climits>
#include <cmath>
#include <deque>
#include <ext/pb_ds/assoc_container.hpp>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
//#include "bits/stdc++.h"

using namespace std;

#ifdef LOCAL
#include "../../_library/cc/debug.h"
#define FILE "test"
#else
#define debug(...) 0
#define FILE "wormsort"
#endif

vector<vector<int>> up, adj;
vector<int> tin, tout, depth;
int t = 0;

void dfs(int u, int p) {
  up[u][0] = p;
  tin[u] = t++;
  for (int i = 1; i < 19; ++i) {
    up[u][i] = up[up[u][i - 1]][i - 1];
  }

  for (int v : adj[u]) {
    if (v != p) {
      depth[v] = depth[u] + 1;
      dfs(v, u);
    }
  }
  tout[u] = t++;
}

int lca(int u, int v) {
  auto anc = [&](int a, int b) {
    return tin[a] <= tin[b] && tout[a] >= tout[b];
  };

  if (anc(u, v))
    return u;
  if (anc(v, u))
    return v;

  for (int i = 18; i >= 0; --i) {
    if (!anc(up[u][i], v))
      u = up[u][i];
  }
  return up[u][0];
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  // Find the LCA of 2 nodes using binary lifting, and compute the differences
  // in depths between the 2 node and their LCA.
  int n, q;
  cin >> n >> q;

  up.assign(n, vector<int>(19));
  adj.resize(n);
  tin.resize(n);
  tout.resize(n);
  depth.resize(n);

  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  dfs(0, 0);

  while (q--) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    int anc = lca(u, v);
    cout << depth[u] + depth[v] - depth[anc] * 2 << '\n';
  }
}
