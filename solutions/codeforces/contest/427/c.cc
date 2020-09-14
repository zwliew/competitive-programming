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
// #include "bits/stdc++.h"

using namespace std;

#ifdef LOCAL
#include "../../_library/cc/debug.h"
#define FILE "test"
#else
#define debug(...) 0
#define FILE "cowjog"
#endif

vector<vector<int>> adj, adjt;
vector<bool> vis;
stack<int> order;
vector<int> cost;
int minCost, minCnt;

void topoSort(int u) {
  if (vis[u])
    return;
  vis[u] = true;
  for (int v : adj[u]) {
    topoSort(v);
  }
  order.push(u);
}

void dfs(int u) {
  if (vis[u])
    return;
  vis[u] = true;
  if (cost[u] < minCost) {
    minCost = cost[u];
    minCnt = 1;
  } else if (cost[u] == minCost) {
    ++minCnt;
  }
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

  // Find the strongly-connected components in the graph. For each SCC, find the
  // minimum vertex cost and number of such costs.
  int n;
  cin >> n;
  adj.resize(n);
  adjt.resize(n);
  vis.resize(n);
  cost.resize(n);

  for (auto& x : cost)
    cin >> x;

  int m;
  cin >> m;
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    --u;
    --v;
    adj[u].push_back(v);
    adjt[v].push_back(u);
  }

  for (int i = 0; i < n; ++i) {
    topoSort(i);
  }

  const int mod = 1e9 + 7;
  int64_t cnt = 1;
  int64_t totalCost = 0;

  vis.assign(n, false);
  while (order.size()) {
    if (!vis[order.top()]) {
      minCnt = 0;
      minCost = INT_MAX;
      dfs(order.top());

      cnt *= minCnt;
      cnt %= mod;
      totalCost += minCost;
    }
    order.pop();
  }

  cout << totalCost << " " << cnt;
}
