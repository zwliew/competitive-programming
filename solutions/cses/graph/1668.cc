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

bool dfs(vector<vector<int>> &adj, vector<int> &col, int u, int c) {
  if (col[u]) {
    return col[u] == c;
  }
  col[u] = c;
  for (auto v : adj[u]) {
    if (!dfs(adj, col, v, c ^ 3)) {
      return false;
    }
  }
  return true;
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
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<int> col(n + 1);
  for (int i = 1; i <= n; ++i) {
    if (!col[i]) {
      if (!dfs(adj, col, i, 1)) {
        cout << "IMPOSSIBLE";
        return 0;
      }
    }
  }

  for (int i = 1; i <= n; ++i) {
    cout << col[i] << ' ';
  }
}
