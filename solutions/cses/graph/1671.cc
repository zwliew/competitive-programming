/*
ID: zhaowei10
TASK:
LANG: C++14
*/
#include "bits/stdc++.h"

using namespace std;

#ifdef LOCAL
#include "../../_library/cpp/debug.h"
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

  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, int>>> adj(n + 1);
  while (m--) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].emplace_back(v, w);
  }

  vector<long long> dist(n + 1, LLONG_MAX);
  dist[1] = 0;
  priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                 greater<pair<long long, int>>>
      q;
  q.emplace(0, 1);
  while (q.size()) {
    auto [d, u] = q.top();
    q.pop();

    if (d > dist[u]) continue;

    for (auto &[v, w] : adj[u]) {
      if (dist[v] > d + w) {
        dist[v] = d + w;
        q.emplace(d + w, v);
      }
    }
  }

  for (int i = 1; i <= n; ++i) {
    cout << dist[i] << ' ';
  }
}
