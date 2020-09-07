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
#define FILE "mootube"
#endif

array<vector<vector<int>>, 2> adj;
vector<bool> vis;
stack<int> order;
vector<int> scc;

void dfs(bool transpose, int u, int s) {
  vis[u] = true;
  for (int v : adj[transpose][u]) {
    if (!vis[v]) {
      dfs(transpose, v, s);
    }
  }

  if (!transpose)
    order.push(u);
  else
    scc[u] = s;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  // Find the strongly-connected components in the directed graph.
  int n, m;
  cin >> n >> m;
  adj[0].resize(n);
  adj[1].resize(n);
  vis.resize(n);
  scc.resize(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    adj[0][u].push_back(v);
    adj[1][v].push_back(u);
  }

  for (int i = 0; i < n; ++i) {
    if (!vis[i]) {
      dfs(false, i, 0);
    }
  }

  int mxs = 0;
  vis.assign(n, false);
  while (order.size()) {
    if (!vis[order.top()]) {
      ++mxs;
      dfs(true, order.top(), mxs);
    }
    order.pop();
  }

  cout << mxs << '\n';
  for (int x : scc) {
    cout << x << ' ';
  }
}
