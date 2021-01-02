#include <bits/stdc++.h>
using namespace std;
#define debug(...) 0
#ifdef LOCAL
#include "../../_library/cc/debug.h"
#endif
// #define FILE ""

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
#if defined(FILE) && !defined(LOCAL)
  freopen(FILE ".in", "r", stdin), freopen(FILE ".out", "w", stdout);
#endif

  int N, M;
  cin >> N >> M;
  vector<vector<pair<int, bool>>> adj(N);
  for (int i = 0; i < M; ++i) {
    int u, v, c;
    cin >> u >> v >> c;
    --u, --v;
    adj[u].emplace_back(v, c);
    adj[v].emplace_back(u, c);
  }

  vector<int> dist(N, 1e9);
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      q;
  dist[0] = 0;
  q.emplace(0, 0);
  while (q.size()) {
    auto u = q.top();
    q.pop();

    if (dist[u.second] < u.first) {
      continue;
    }
    for (auto& [v, c] : adj[u.second]) {
      if (dist[v] > u.first + c) {
        dist[v] = u.first + c;
        q.emplace(dist[v], v);
      }
    }
  }
  cout << dist[N - 1];
}
