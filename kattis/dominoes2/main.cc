#include <stdio.h>

#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

using ll = long long;
using ld = long double;

void dfs(unordered_set<int> &vis, vector<vector<int>> &adj, int u) {
  for (int v : adj[u]) {
    if (!vis.count(v)) {
      vis.emplace(v);
      dfs(vis, adj, v);
    }
  }
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  // Flood fill
  int t;
  cin >> t;
  while (t--) {
    int n, m, l;
    cin >> n >> m >> l;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
      int x, y;
      cin >> x >> y;
      adj[x].emplace_back(y);
    }

    unordered_set<int> visited;
    int count = 0;
    for (int i = 0; i < l; ++i) {
      int z;
      cin >> z;
      if (!visited.count(z)) {
        visited.emplace(z);
        dfs(visited, adj, z);
      }
    }

    cout << visited.size() << '\n';
  }
}
