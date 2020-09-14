#include <algorithm>
#include <array>
#include <bitset>
#include <chrono>
#include <climits>
#include <cmath>
#include <cstring>
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
#define FILE ""
#endif

vector<vector<int>> adj, adjt, comp;
vector<bool> vis;
vector<int> order;

void topoSort(int u) {
  if (vis[u])
    return;
  vis[u] = true;
  for (int v : adj[u]) {
    topoSort(v);
  }
  order.push_back(u);
}

void dfs(int u) {
  if (vis[u])
    return;
  vis[u] = true;
  comp.back().push_back(u);
  for (int v : adjt[u]) {
    dfs(v);
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  // Textbook implementation of Kosaraju's SCC algorithm
  int n, m;
  cin >> n >> m;

  adj.resize(n);
  adjt.resize(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adjt[v].push_back(u);
  }

  vis.assign(n, false);
  for (int i = 0; i < n; ++i) {
    if (!vis[i]) {
      topoSort(i);
    }
  }
  reverse(order.begin(), order.end());

  vis.assign(n, false);
  for (int x : order) {
    if (!vis[x]) {
      comp.resize(comp.size() + 1);
      dfs(x);
    }
  }

  cout << comp.size() << '\n';
  for (auto& v : comp) {
    cout << v.size() << ' ';
    for (int x : v) {
      cout << x << ' ';
    }
    cout << '\n';
  }
}
