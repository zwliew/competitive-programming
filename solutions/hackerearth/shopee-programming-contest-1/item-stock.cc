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

void dfs(vector<vector<int>> &adj, vector<bool> &fixed,
         vector<int> &lowestFixed, vector<int> &qv, vector<int> &qtyMult,
         int curLowestFixed, int curMult, int u) {
  lowestFixed[u] = curLowestFixed;
  if (u != 1) {
    qtyMult[u] = curMult * qv[u];
  } else {
    qtyMult[u] = 1;
  }
  for (int v : adj[u]) {
    dfs(adj, fixed, lowestFixed, qv, qtyMult, fixed[u] ? u : curLowestFixed,
        fixed[u] ? 1 : qtyMult[u], v);
  }
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
  vector<int> pv(n + 1), qv(n + 1), sv(n + 1);
  vector<bool> fixed(n + 1);
  sv[1] = m;
  fixed[1] = true;
  for (int i = 2; i <= n; ++i) {
    int x, p, q;
    cin >> x >> p >> q;
    pv[i] = p;
    qv[i] = q;
    fixed[i] = x == 2;
    if (x == 2) {
      int s;
      cin >> s;
      sv[i] = s;
      adj[p].emplace_back(i);
    } else {
      adj[p].emplace_back(i);
    }
  }

  vector<int> lowestFixed(n + 1), qtyMult(n + 1);
  dfs(adj, fixed, lowestFixed, qv, qtyMult, 0, 1, 1);

  for (int i = 2; i <= n; ++i) {
    if (fixed[i]) {
      int parent = lowestFixed[i];
      sv[parent] -= qtyMult[i] * sv[i];
    }
  }

  for (int i = 1; i <= n; ++i) {
    if (!fixed[i]) {
      sv[i] = sv[pv[i]] / qv[i];
    }
    cout << sv[i] << '\n';
  }
}

