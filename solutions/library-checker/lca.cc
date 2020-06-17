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

void dfs(vector<vector<int>> &adj, vector<int> &first, vector<int> &depth,
         vector<int> &euler, int u) {
  first[u] = euler.size();
  euler.emplace_back(u);
  for (int v : adj[u]) {
    if (first[v] == -1) {
      depth[v] = depth[u] + 1;
      dfs(adj, first, depth, euler, v);
      euler.emplace_back(u);
    }
  }
}

int fs(vector<int> &p, int u) { return p[u] == u ? u : p[u] = fs(p, p[u]); }
void unite(vector<int> &p, int u, int v) { p[fs(p, u)] = fs(p, v); }

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  // Compute Euler tour then compute RMQ with Arpa's trick
  int n, q;
  cin >> n >> q;
  vector<int> p(n - 1);
  for (auto &x : p) cin >> x;
  vector<vector<int>> adj(n);
  for (int i = 0; i < n - 1; ++i) {
    adj[p[i]].emplace_back(i + 1);
    adj[i + 1].emplace_back(p[i]);
  }

  vector<int> first(n, -1), depth(n);
  depth[0] = 0;
  vector<int> euler;
  dfs(adj, first, depth, euler, 0);

  vector<vector<pair<int, int>>> queries(euler.size());
  for (int i = 0; i < q; ++i) {
    int l, r;
    cin >> l >> r;
    if (first[l] > first[r]) swap(l, r);
    queries[first[r]].emplace_back(first[l], i);
  }

  vector<int> parent(euler.size());
  iota(parent.begin(), parent.end(), 0);
  stack<int> s;
  vector<int> ans(q);
  for (int i = 0; i < (int)euler.size(); ++i) {
    while (s.size() && depth[euler[s.top()]] > depth[euler[i]]) {
      unite(parent, s.top(), i);
      s.pop();
    }
    s.push(i);

    for (auto &[l, idx] : queries[i]) {
      ans[idx] = euler[fs(parent, l)];
    }
  }

  for (auto x : ans) cout << x << '\n';
}
