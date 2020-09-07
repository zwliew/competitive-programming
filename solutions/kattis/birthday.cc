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
vector<int> lvl, dp;
bool ok;

void dfs(int u) {
  dp[u] = -1;
  for (int v : adj[u]) {
    if (!lvl[v]) {
      lvl[v] = lvl[u] + 1;
      dfs(v);
      dp[u] += dp[v];
    } else if (lvl[v] < lvl[u]) {
      ++dp[u];
    } else if (lvl[v] > lvl[u]) {
      --dp[u];
    }
  }
  if (lvl[u] > 1 && !dp[u]) {
    ok = false;
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  // Check if a bridge exists in the graph, or if there is more than 1 connected
  // component in the graph.
  int n, m;
  while (cin >> n >> m && (n || m)) {
    ok = true;
    lvl.assign(n, 0);
    dp.assign(n, 0);
    adj.assign(n, vector<int>());
    for (int i = 0; i < m; ++i) {
      int u, v;
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    lvl[0] = 1;
    dfs(0);

    for (int u = 0; u < n && ok; ++u) {
      if (!lvl[u]) {
        ok = false;
      }
    }

    cout << (ok ? "No" : "Yes") << '\n';
  }
}
