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

int valSum(unordered_set<int> &vis, vector<vector<int>> &adj, vector<int> &val,
           int u) {
  int sum = val[u];
  for (int v : adj[u]) {
    if (!vis.count(v)) {
      vis.emplace(v);
      sum += valSum(vis, adj, val, v);
    }
  }
  return sum;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  // Within a connected component, money can be transferred anywhere.
  // Hence, we determine if the sum of values of all vertices in each connected
  // component is 0.
  int n, m;
  cin >> n >> m;
  vector<int> val(n);
  vector<vector<int>> adj(n);
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    val[i] = x;
  }
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
  }

  unordered_set<int> vis;
  for (int i = 0; i < n; ++i) {
    if (!vis.count(i)) {
      vis.emplace(i);
      if (valSum(vis, adj, val, i) != 0) {
        cout << "IMPOSSIBLE";
        return 0;
      }
    }
  }
  cout << "POSSIBLE";
}
