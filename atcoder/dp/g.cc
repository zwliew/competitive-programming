#include <stdio.h>

#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <deque>
#include <fstream>
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

void dfs(vector<vector<int>> &adj, vector<int> &dp, vector<bool> &vis, int i) {
  vis[i] = 1;
  for (int v : adj[i]) {
    if (!vis[v]) {
      dfs(adj, dp, vis, v);
    }
    dp[i] = max(dp[i], dp[v] + 1);
  }
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;
  vector<vector<int>> adj(n);
  for (int i = 0; i < m; ++i) {
    int x, y;
    cin >> x >> y;
    adj[x - 1].emplace_back(y - 1);
  }

  vector<bool> vis(n);
  vector<int> dp(n);
  for (int i = 0; i < n; ++i) {
    dfs(adj, dp, vis, i);
    vis[i] = 1;
  }

  cout << *max_element(dp.begin(), dp.end());
}
