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
#define FILE "mootube"
#endif

bool dfs(vector<vector<int>>& adj,
         vector<int>& vis,
         vector<int>& order,
         int u) {
  vis[u] = 1;
  for (int v : adj[u]) {
    if (vis[v] == 1)
      return false;
    if (!vis[v] && !dfs(adj, vis, order, v))
      return false;
  }
  order.emplace_back(u);
  vis[u] = 2;
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
  vector<vector<int>> adj(n);
  while (m--) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    adj[u].emplace_back(v);
  }
  vector<int> order;
  vector<int> vis(n);
  for (int i = 0; i < n; ++i) {
    if (!vis[i] && !dfs(adj, vis, order, i)) {
      cout << "IMPOSSIBLE";
      return 0;
    }
  }
  reverse(order.begin(), order.end());
  for (int x : order) {
    cout << x + 1 << ' ';
  }
}
