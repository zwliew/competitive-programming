#include <algorithm>
#include <array>
#include <bitset>
#include <chrono>
#include <climits>
#include <cmath>
#include <cstring>
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
#define FILE "berries"
#endif

int n;
array<vector<int>, 400> adj;
array<int, 400> a;
vector<int> order;
vector<bool> vis(400);
array<int, 400> dp;

void topoSort(int u) {
  if (vis[u])
    return;
  vis[u] = true;
  for (int v : adj[u]) {
    topoSort(v);
  }
  order.push_back(u);
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  // Find the topological sort order to then find the longest path in the DAG.
  // Brute force optimizing every vertex, and find the minimum longest path
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (int i = 0; i < n; ++i) {
    int c;
    cin >> c;
    for (int j = 0; j < c; ++j) {
      int x;
      cin >> x;
      adj[i].push_back(x - 1);
    }
  }

  for (int i = 0; i < n; ++i) {
    if (!vis[i]) {
      topoSort(i);
    }
  }

  int ans = INT_MAX;
  for (int i = 0; i < n; ++i) {
    int prev = a[i];
    a[i] = 0;

    fill(dp.begin(), dp.end(), 0);
    for (int u : order) {
      for (int v : adj[u]) {
        dp[u] = max(dp[u], dp[v]);
      }
      dp[u] += a[u];
    }

    ans = min(ans, dp[n - 1]);

    a[i] = prev;
  }

  cout << ans;
}
