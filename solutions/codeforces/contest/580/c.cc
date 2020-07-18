/*
ID: zhaowei10
TASK:
LANG: C++14
*/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 0
#endif

int n, m;
int dfs(vector<vector<int>> &adj, vector<bool> &cat, int u, int p,
        int curCats) {
  curCats = cat[u] ? curCats + 1 : 0;
  if (curCats > m) {
    return 0;
  }
  int count = 0;
  int childrenCnt = 0;
  for (int v : adj[u]) {
    if (v != p) {
      ++childrenCnt;
      count += dfs(adj, cat, v, u, curCats);
    }
  }
  if (!childrenCnt) return 1;
  return count;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << fixed;

#ifdef LOCAL
  freopen("test.in", "r", stdin);
  freopen("test.out", "w", stdout);
#else
#endif

  cin >> n >> m;
  vector<vector<int>> adj(n + 1);
  vector<bool> cat(n + 1);
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    cat[i] = x;
  }
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
  }

  cout << dfs(adj, cat, 1, 0, 0);
}
