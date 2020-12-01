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
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

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

  int V, E, C, K, M;
  cin >> V >> E >> C >> K >> M;

  int cycle = min(K, M);
  if (C < cycle) {
    cout << -1;
    return 0;
  }

  vector<vector<array<int, 2>>> adj(V);
  for (int i = 0; i < E; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    --u, --v;
    adj[u].push_back({w, v});
    adj[v].push_back({w, u});
  }

  vector<int> avail(C);
  for (auto& x : avail) {
    cin >> x;
    --x;
  }

  vector<int64_t> dist(V, 1e18);
  dist[0] = 0;
  priority_queue<array<int64_t, 2>> pq;
  pq.push({0, 0});
  while (pq.size()) {
    auto u = pq.top();
    pq.pop();
    u[0] = -u[0];
    if (u[0] > dist[u[1]])
      continue;
    for (auto v : adj[u[1]]) {
      auto d = u[0] + v[0];
      if (d < dist[v[1]]) {
        dist[v[1]] = d;
        pq.push({-d, v[1]});
      }
    }
  }

  sort(avail.begin(), avail.end(),
       [&](auto& x, auto& y) { return dist[x] < dist[y]; });
  int64_t ans = 0;
  int cnt = 0;
  for (int x : avail) {
    if (dist[x] >= 1e18 || cnt == cycle)
      break;
    ++cnt;
    ans = max(ans, dist[x]);
  }

  cout << (cnt < cycle ? -1 : ans * 2);
}
