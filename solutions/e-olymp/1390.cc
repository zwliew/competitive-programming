/*
ID: zhaowei10
TASK:
LANG: C++14
*/
#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>

using namespace __gnu_cxx;
using namespace __gnu_pbds;
using namespace std;

#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 0
#endif

#define eb emplace_back

using ll = long long;
using ld = long double;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;
using vc = vector<char>;
using vb = vector<bool>;
using vll = vector<ll>;

bool dfs(vector<unordered_set<int>> &adj, vb &vis, int u, int p) {
  vis[u] = true;
  for (auto v : adj[u]) {
    if (v == p) continue;
    if (vis[v]) return true;
    if (dfs(adj, vis, v, u)) {
      return true;
    }
  }
  return false;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(9);

#ifdef LOCAL
  freopen("test.in", "r", stdin);
  freopen("test.out", "w", stdout);
#else
#endif

  int n, m;
  cin >> n >> m;
  vector<unordered_set<int>> adj(n + 1);
  while (m--) {
    int u, v;
    cin >> u >> v;
    adj[u].emplace(v);
    adj[v].emplace(u);
  }

  vb visited(n + 1);
  for (int i = 1; i <= n; ++i) {
    if (!visited[i]) {
      if (dfs(adj, visited, i, 0)) {
        cout << "YES";
        return 0;
      }
    }
  }

  cout << "NO";
}
