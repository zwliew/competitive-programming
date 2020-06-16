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

int start = 0, ending = 0;

bool dfs(vector<vector<int>> &adj, vector<bool> &vis, vector<int> &path, int u,
         int p = 0) {
  if (vis[u]) {
    start = u;
    ending = p;
    return true;
  }
  path.push_back(u);
  vis[u] = true;
  for (auto v : adj[u]) {
    if (v == p) continue;
    if (dfs(adj, vis, path, v, u)) {
      return true;
    }
  }
  path.pop_back();
  return false;
}

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

  vector<bool> vis(n + 1);
  vector<int> path;
  for (int i = 1; i <= n; ++i) {
    if (!vis[i]) {
      if (dfs(adj, vis, path, i)) {
        bool started = false;
        vector<int> ans;
        for (int j = 0; j < (int)path.size(); ++j) {
          if (path[j] == start) {
            started = true;
          }
          if (started) {
            ans.emplace_back(path[j]);
          }
          if (path[j] == ending) {
            started = false;
          }
        }
        ans.emplace_back(start);

        cout << ans.size() << '\n';
        for (auto x : ans) cout << x << ' ';
        return 0;
      }
    }
  }

  cout << "IMPOSSIBLE";
}
