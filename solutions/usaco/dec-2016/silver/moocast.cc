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
#define FILE "moocast"
#endif

int dfs(vector<vector<int>>& adj, vector<bool>& vis, int u) {
  vis[u] = true;
  int ans = 1;
  for (int v : adj[u]) {
    if (!vis[v]) {
      ans += dfs(adj, vis, v);
    }
  }
  return ans;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int n;
  cin >> n;
  vector<pair<int, int>> coords(n);
  vector<int> p(n);
  for (int i = 0; i < n; ++i) {
    cin >> coords[i].first >> coords[i].second >> p[i];
  }

  vector<vector<int>> adj(n);
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      int dx = coords[i].first - coords[j].first;
      int dy = coords[i].second - coords[j].second;
      dx *= dx;
      dy *= dy;
      int d = dx + dy;
      if (d <= p[i] * p[i]) {
        adj[i].emplace_back(j);
      }
      if (d <= p[j] * p[j]) {
        adj[j].emplace_back(i);
      }
    }
  }

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    vector<bool> vis(n);
    ans = max(ans, dfs(adj, vis, i));
  }
  cout << ans;
}
