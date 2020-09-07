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

vector<vector<int>> adj;
vector<unordered_set<int>> adjDel;
vector<int> lvl, dp;

void dfs(int u, int p) {
  dp[u] = -1;
  for (int v : adj[u]) {
    if (!lvl[v]) {
      lvl[v] = lvl[u] + 1;
      dfs(v, u);
      dp[u] += dp[v];
    } else if (lvl[v] > lvl[u]) {
      --dp[u];
    } else if (lvl[v] < lvl[u]) {
      ++dp[u];
    }
  }
  if (lvl[u] > 1 && !dp[u]) {
    adjDel[u].erase(p);
    adjDel[p].erase(u);
  }
}

void dfs2(int u) {
  lvl[u] = 1;
  for (int v : adjDel[u]) {
    if (!lvl[v]) {
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

  // Find the bridges in the graph, delete them, and DFS again from node 0 to
  // find the size of the still-connected component.
  int n, m;
  cin >> n >> m;
  adj.resize(n);
  adjDel.resize(n);
  lvl.resize(n);
  dp.resize(n);
  while (m--) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
    adjDel[u].insert(v);
    adjDel[v].insert(u);
  }

  lvl[0] = 1;
  dfs(0, -1);

  lvl.assign(n, 0);
  dfs2(0);

  cout << accumulate(lvl.begin(), lvl.end(), 0);
}
