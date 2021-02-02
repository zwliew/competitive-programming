#include <bits/stdc++.h>
using namespace std;
#define debug(...) 0
#ifdef LOCAL
#include "../../_library/cc/debug.h"
#endif
// #define FILE "milkvisits"

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
#if defined(FILE) && !defined(LOCAL)
  freopen(FILE ".in", "r", stdin), freopen(FILE ".out", "w", stdout);
#endif

  int N, M, Q, S;
  while (cin >> N >> M >> Q >> S && N) {
    vector<array<int, 3>> edges(M);
    for (int i = 0; i < M; ++i) {
      int u, v, w;
      cin >> u >> v >> w;
      edges.push_back({u, v, w});
    }

    const int INF = 1e9;
    vector<int> dist(N, INF);
    dist[S] = 0;
    bool relaxed = true;
    for (int i = 0; i < N - 1 && relaxed; ++i) {
      relaxed = false;
      for (auto& [u, v, w] : edges) {
        if (dist[u] < INF && dist[u] + w < dist[v]) {
          dist[v] = dist[u] + w;
          relaxed = true;
        }
      }
    }

    if (relaxed) {
      for (int i = 0; i < N - 1; ++i) {
        for (auto& [u, v, w] : edges) {
          if (dist[u] < INF && dist[u] + w < dist[v]) {
            dist[v] = -INF;
          }
        }
      }
    }

    for (int i = 0; i < Q; ++i) {
      int v;
      cin >> v;
      if (dist[v] == INF) {
        cout << "Impossible";
      } else if (dist[v] == -INF) {
        cout << "-Infinity";
      } else {
        cout << dist[v];
      }
      cout << "\n";
    }
    cout << "\n";
  }
}
