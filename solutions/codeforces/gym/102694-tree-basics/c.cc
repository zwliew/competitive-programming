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

vector<vector<int>> adj, up;
vector<int> depth, tin, tout;
int t = 0;

void dfs(int u, int p) {
  tin[u] = t++;
  up[u][0] = p;
  for (int i = 1; i < 20; ++i) {
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
  if (anc(v, u))
    return v;
  if (anc(u, v))
    return u;
  for (int l = 19; l >= 0; --l) {
    if (!anc(up[u][l], v))
      u = up[u][l];
  }
  return up[u][0];
}

int parent(int u, int d) {
  for (int l = 0; l < 20 && d; ++l, d >>= 1) {
    if (d & 1) {
      u = up[u][l];
    }
  }
  return u;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  // Compute the LCA to find the distance between 2 nodes.
  // Compute the node that we can move to using the LCA and distance.
  int n;
  cin >> n;

  adj.resize(n);
  up.assign(n, vector<int>(20));
  depth.resize(n);
  tin.resize(n);
  tout.resize(n);

  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  dfs(0, 0);

  int q;
  cin >> q;
  while (q--) {
    int u, v, c;
    cin >> u >> v >> c;
    --u, --v;

    int anc = lca(u, v);
    int d = depth[u] + depth[v] - depth[anc] * 2;
    if (c <= depth[u] - depth[anc]) {
      cout << parent(u, c) + 1;
    } else {
      cout << parent(v, max(0, d - c)) + 1;
    }
    cout << '\n';
  }
}
