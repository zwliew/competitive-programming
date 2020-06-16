/*
ID: zhaowei10
TASK:
LANG: C++14
*/
#include "bits/extc++.h"

using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;

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
  vector<vector<int>> adj(n + 1);
  while (m--) {
    int u, v;
    cin >> u >> v;
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
  }

  vector<int> p(n + 1);
  vector<int> dist(n + 1, INT_MAX);
  dist[1] = 1;
  queue<int> q;
  q.push(1);
  while (q.size()) {
    auto u = q.front();
    q.pop();
    if (u == n) {
      cout << dist[n] << '\n';
      vector<int> ans;
      while (u) {
        ans.push_back(u);
        u = p[u];
      }
      for (int i = ans.size() - 1; ~i; --i) {
        cout << ans[i] << ' ';
      }
      return 0;
    }
    for (auto v : adj[u]) {
      if (dist[v] > dist[u] + 1) {
        dist[v] = dist[u] + 1;
        p[v] = u;
        q.push(v);
      }
    }
  }
  cout << "IMPOSSIBLE";
}
