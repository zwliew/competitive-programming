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
#define FILE ""
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  // Brute force and try lengthening each of the edges on the original shortest
  // path
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

  vector<int> p(n, -1);
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      q;
  vector<int> dist(n, INT_MAX);
  dist[0] = 0;
  q.emplace(0, 0);
  while (q.size()) {
    auto [d, u] = q.top();
    q.pop();

    if (u == n - 1)
      continue;
    if (d > dist[u])
      continue;

    for (auto& [v, w] : adj[u]) {
      if (dist[v] > d + w) {
        dist[v] = d + w;
        q.emplace(dist[v], v);
        p[v] = u;
      }
    }
  }

  vector<pair<int, int>> edges;
  for (int cur = n - 1; cur != -1; cur = p[cur]) {
    edges.emplace_back(p[cur], cur);
  }

  int origDist = dist[n - 1];
  int maxDist = origDist;
  for (auto& [bu, bv] : edges) {
    dist.assign(n, INT_MAX);
    dist[0] = 0;
    q.emplace(0, 0);
    while (q.size()) {
      auto [d, u] = q.top();
      q.pop();

      if (u == n - 1)
        continue;
      if (d > dist[u])
        continue;

      for (auto [v, w] : adj[u]) {
        if ((u == bu && v == bv) || (u == bv && v == bu)) {
          w *= 2;
        }
        if (d + w < dist[v]) {
          dist[v] = d + w;
          q.emplace(dist[v], v);
        }
      }
    }
    maxDist = max(maxDist, dist[n - 1]);
  }

  cout << maxDist - origDist;
}
