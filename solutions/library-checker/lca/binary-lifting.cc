#include <algorithm>
#include <array>
#include <bitset>
#include <chrono>
#include <climits>
#include <cmath>
#include <deque>
#include <ext/pb_ds/assoc_container.hpp>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
//#include "bits/stdc++.h"

using namespace std;

#ifdef LOCAL
#include "../../_library/cc/debug.h"
#define FILE "test"
#else
#define debug(...) 0
#define FILE "wormsort"
#endif

vector<int> p, tin, tout;
vector<vector<int>> adj, up;
int t = 0;

void dfs(int u) {
  tin[u] = t++;
  up[u][0] = p[u];
  for (int i = 1; i < 20; ++i) {
    up[u][i] = up[up[u][i - 1]][i - 1];
  }
  for (int v : adj[u]) {
    dfs(v);
  }
  tout[u] = t++;
}

int lca(int u, int v) {
  auto anc = [&](int u, int v) {
    return tin[u] <= tin[v] && tout[u] >= tout[v];
  };
  if (anc(u, v))
    return u;
  if (anc(v, u))
    return v;
  for (int i = 19; i >= 0; --i) {
    if (!anc(up[u][i], v))
      u = up[u][i];
  }
  return up[u][0];
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int n, q;
  cin >> n >> q;
  p.resize(n);
  tin.resize(n);
  tout.resize(n);
  up.assign(n, vector<int>(20));
  adj.resize(n);
  for (int i = 1; i < n; ++i) {
    cin >> p[i];
    adj[p[i]].push_back(i);
  }

  dfs(0);

  while (q--) {
    int u, v;
    cin >> u >> v;
    cout << lca(u, v) << '\n';
  }
}
