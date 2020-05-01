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
using vi = vector<int>;

void dfs(vector<bool> &visited, vector<vector<int>> &adj, int u) {
  visited[u] = 1;
  for (int v : adj[u]) {
    if (visited[v]) continue;
    dfs(visited, adj, v);
  }
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  // Determine connectivity to node 0
  int n, m;
  cin >> n >> m;
  vector<vector<int>> adj(n);
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    adj[a].emplace_back(b);
    adj[b].emplace_back(a);
  }

  vector<bool> visited(n);
  dfs(visited, adj, 0);

  bool ok = 1;
  for (int i = 0; i < n; ++i) {
    if (!visited[i]) {
      cout << i + 1 << '\n';
      ok = 0;
    }
  }
  if (ok) {
    cout << "Connected";
  }
}
