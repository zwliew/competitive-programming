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
#define FILE "closing"
#endif

// void dfs(vector<vector<int>>& adj,
//          vector<bool>& vis,
//          vector<bool>& disabled,
//          int u) {
//   vis[u] = true;
//   for (int v : adj[u]) {
//     if (!vis[v] && !disabled[v]) {
//       dfs(adj, vis, disabled, v);
//     }
//   }
// }

struct DSU {
  vector<int> p;

  DSU(int n) {
    p.resize(n);
    iota(p.begin(), p.end(), 0);
  }

  bool join(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v)
      return false;
    p[u] = v;
    return true;
  }

  int find(int u) { return u == p[u] ? u : (p[u] = find(p[u])); }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int n, m;
  cin >> n >> m;
  vector<vector<int>> adj(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    --u;
    --v;
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
  }

  // Slower solution: DFS after every removal.
  // vector<bool> disabled(n);
  // vector<bool> vis(n);
  // for (int i = 0; i < n; ++i) {
  //   for (int j = 0; j < n; ++j) {
  //     if (!disabled[j]) {
  //       dfs(adj, vis, disabled, j);
  //       break;
  //     }
  //   }
  //   if (accumulate(vis.begin(), vis.end(), 0) != n - i - 1) {
  //     cout << "NO\n";
  //   } else {
  //     cout << "YES\n";
  //   }
  //   int x;
  //   cin >> x;
  //   --x;
  //   vis.assign(n, 0);
  //   disabled[x] = true;
  // }

  // Faster solution: Keep track of DSU in reverse.
  // Instead of removing vertices forwards, re-add vertices in reverse.
  vector<int> order(n);
  for (int i = 0; i < n; ++i) {
    cin >> order[i];
    --order[i];
  }

  vector<bool> added(n);
  DSU dsu(n);
  int cc = 0;
  for (int i = n - 1; i >= 0; --i) {
    added[order[i]] = true;
    ++cc;
    for (int v : adj[order[i]]) {
      if (added[v] && dsu.join(order[i], v)) {
        --cc;
      }
    }
    order[i] = cc <= 1;
  }

  for (int x : order) {
    cout << (x ? "YES\n" : "NO\n");
  }
}
