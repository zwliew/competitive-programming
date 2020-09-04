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
#define FILE "fenceplan"
#endif

void dfs(vector<vector<int>>& adj,
         vector<bool>& vis,
         tuple<int, int, int, int>& bounds,
         vector<pair<int, int>>& coords,
         int u) {
  vis[u] = true;
  get<0>(bounds) = max(get<0>(bounds), coords[u].first);
  get<1>(bounds) = min(get<1>(bounds), coords[u].first);
  get<2>(bounds) = max(get<2>(bounds), coords[u].second);
  get<3>(bounds) = min(get<3>(bounds), coords[u].second);
  for (int v : adj[u]) {
    if (!vis[v]) {
      dfs(adj, vis, bounds, coords, v);
    }
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

  vector<pair<int, int>> coords(n);
  for (int i = 0; i < n; ++i) {
    cin >> coords[i].first >> coords[i].second;
  }

  vector<vector<int>> adj(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    --u;
    --v;
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
  }

  vector<bool> vis(n);
  vector<tuple<int, int, int, int>> bounds;
  int ans = INT_MAX;
  for (int u = 0; u < n; ++u) {
    if (!vis[u]) {
      bounds.emplace_back(INT_MIN, INT_MAX, INT_MIN, INT_MAX);
      dfs(adj, vis, bounds.back(), coords, u);
      ans = min(ans, (get<0>(bounds.back()) - get<1>(bounds.back()) +
                      get<2>(bounds.back()) - get<3>(bounds.back())) *
                         2);
    }
  }
  cout << ans;
}
