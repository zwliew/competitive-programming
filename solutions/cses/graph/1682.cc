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

vector<bool> vis;
vector<vector<int>> adj, adjr;
vector<int> order;

void dfs1(int u) {
  vis[u] = true;
  for (int v : adj[u]) {
    if (!vis[v]) {
      dfs1(v);
    }
  }
  order.emplace_back(u);
}

void dfs2(int u) {
  vis[u] = true;
  for (int v : adjr[u]) {
    if (!vis[v]) {
      dfs2(v);
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
  adj.resize(n);
  adjr.resize(n);
  vis.resize(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    adj[u].emplace_back(v);
    adjr[v].emplace_back(u);
  }

  for (int i = 0; i < n; ++i) {
    if (!vis[i]) {
      dfs1(i);
    }
  }
  vis.assign(n, false);
  dfs2(order.back());
  for (int i = 0; i < n; ++i) {
    if (!vis[i]) {
      cout << "NO\n" << i + 1 << ' ' << order.back() + 1;
      return 0;
    }
  }
  cout << "YES";
}
