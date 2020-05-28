#include <stdio.h>

#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

using ll = long long;
using ld = long double;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;
using vc = vector<char>;
using vb = vector<bool>;

#define eb emplace_back

int compute(vector<unordered_set<int>> &p, vector<tuple<int, int, int>> &edges,
            vb &visited, int u) {
  int cost = 0;
  for (int ei : p[u]) {
    if (visited[ei]) continue;
    auto [u1, v, w] = edges[ei];
    if (u == v) swap(u1, v);
    visited[ei] = 1;
    cost += compute(p, edges, visited, v) + w;
  }
  return cost;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  // Keep track a predecessor edge list (the adjacent edge along the shortest
  // path that leads to a vertex) for each vertex.
  // Then, traverse (DFS/BFS) along the shortest paths graph to compute the
  // total cost.
  int v, e;
  cin >> v >> e;
  vector<vi> adj(v);
  vector<tuple<int, int, int>> edges;
  for (int i = 0; i < e; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    edges.emplace_back(u, v, w);
    adj[u].emplace_back(i);
    adj[v].emplace_back(i);
  }

  priority_queue<ii, vii, greater<ii>> q;
  vector<unordered_set<int>> p(v);
  vector<int> dist(v, 1e9);
  dist[0] = 0;
  q.emplace(0, 0);
  while (q.size()) {
    auto [d, u] = q.top();
    q.pop();

    if (u == v - 1) continue;
    if (d > dist[u]) continue;

    for (auto ei : adj[u]) {
      auto [u1, v, w] = edges[ei];
      int ndist = d + w;
      if (u == v) swap(u1, v);
      if (ndist < dist[v]) {
        q.emplace(ndist, v);
        p[v] = unordered_set<int>();
        p[v].emplace(ei);
        dist[v] = ndist;
      } else if (ndist == dist[v]) {
        p[v].emplace(ei);
      }
    }
  }

  vb visited(edges.size());
  cout << compute(p, edges, visited, v - 1) * 2;
}
