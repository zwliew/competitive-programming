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

void compute(vector<vector<pair<int, int>>>& adj, vector<int64_t>& d, int u) {
  d[u] = 0;
  priority_queue<pair<int64_t, int>, vector<pair<int64_t, int>>,
                 greater<pair<int64_t, int>>>
      pq;
  pq.emplace(0, u);
  while (pq.size()) {
    auto [cd, cu] = pq.top();
    pq.pop();
    if (cd > d[cu])
      continue;
    for (auto& [v, w] : adj[cu]) {
      if (cd + w < d[v]) {
        d[v] = cd + w;
        pq.emplace(d[v], v);
      }
    }
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int N, M;
  cin >> N >> M;
  vector<vector<pair<int, int>>> adj1(N), adj2(N);
  for (int i = 0; i < M; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    --u, --v;
    adj1[u].emplace_back(v, w);
    adj2[v].emplace_back(u, w);
  }

  vector<int64_t> d1(N, 1e18), d2(N, 1e18);
  compute(adj1, d1, 0);
  compute(adj2, d2, N - 1);

  int64_t ans = LLONG_MAX;
  for (int i = 0; i < N; ++i) {
    for (auto& [v, w] : adj1[i]) {
      ans = min(ans, d1[i] + d2[v] + w / 2);
    }
  }
  cout << ans;

  // Alternative solution by keeping track of a 2D distance array
  //   int N, M;
  //   cin >> N >> M;
  //   vector<vector<array<int64_t, 2>>> adj(N);
  //   for (int i = 0; i < M; ++i) {
  //     int u, v, w;
  //     cin >> u >> v >> w;
  //     --u, --v;
  //     adj[u].push_back({w, v});
  //   }
  //   vector<vector<int64_t>> dist(2, vector<int64_t>(N, LLONG_MAX));
  //   priority_queue<array<int64_t, 3>, vector<array<int64_t, 3>>,
  //                  greater<array<int64_t, 3>>>
  //       q;
  //   dist[false][0] = 0;
  //   q.push({0, false, 0});
  //   while (q.size()) {
  //     auto [d, used, u] = q.top();
  //     q.pop();
  //     if (d > dist[used][u])
  //       continue;
  //     for (auto& [w, v] : adj[u]) {
  //       if (d + w < dist[used][v]) {
  //         dist[used][v] = d + w;
  //         q.push({dist[used][v], used, v});
  //       }
  //       if (!used && d + w / 2 < dist[true][v]) {
  //         dist[true][v] = d + w / 2;
  //         q.push({dist[true][v], true, v});
  //       }
  //     }
  //   }
  //   cout << dist[true][N - 1];
}
