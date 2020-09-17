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
#define FILE "rblock"
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, int>>> adj(n);
  for (int i = 0; i < m; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    --u, --v;
    adj[u].emplace_back(v, w);
    adj[v].emplace_back(u, w);
  }

  vector<int> parent(n, -1);
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      q;
  q.emplace(0, 0);
  vector<int> dist(n, INT_MAX);
  dist[0] = 0;
  while (q.size()) {
    auto p = q.top();
    int d = p.first;
    int u = p.second;
    q.pop();

    if (d > dist[u])
      continue;
    for (int i = 0; i < adj[u].size(); ++i) {
      int v = adj[u][i].first;
      int w = adj[u][i].second;
      if (dist[v] > dist[u] + w) {
        dist[v] = dist[u] + w;
        q.emplace(dist[v], v);
        parent[v] = u;
      }
    }
  }

  vector<pair<int, int>> path;
  for (int u = n - 1; u != -1; u = parent[u]) {
    path.emplace_back(parent[u], u);
  }

  int origDist = dist[n - 1];
  int maxDist = 0;
  for (auto &p : path) {
    int bu = p.first;
    int bv = p.second;
    q.emplace(0, 0);
    dist.assign(n, INT_MAX);
    dist[0] = 0;
    while (q.size()) {
      auto p = q.top();
      int d = p.first;
      int u = p.second;
      q.pop();

      if (d > dist[u])
        continue;
      for (int i = 0; i < adj[u].size(); ++i) {
        int v = adj[u][i].first;
        int w = adj[u][i].second;
        int nw = w;
        if ((v == bu && u == bv) || (u == bu && v == bv)) {
          nw *= 2;
        }
        if (dist[v] > dist[u] + nw) {
          dist[v] = dist[u] + nw;
          q.emplace(dist[v], v);
        }
      }
    }

    maxDist = max(maxDist, dist[n - 1]);
  }
  cout << maxDist - origDist;
}
