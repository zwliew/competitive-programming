#include <algorithm>
#include <array>
#include <bitset>
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

typedef long long ll;

vector<int> a, dp, ans;
vector<vector<int>> adj;

void dfs(int u, int p = -1) {
  dp[u] = a[u];
  for (auto v : adj[u]) {
    if (v == p) continue;
    dfs(v, u);
    dp[u] += max(0, dp[v]);
  }
}

void dfs2(int u, int p = -1, int pd = 0) {
  ans[u] = dp[u] + pd;
  for (auto v : adj[u]) {
    if (p == v) continue;
    dfs2(v, u, max(0, ans[u] - max(0, dp[v])));
  }
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  a = dp = ans = vector<int>(n);
  adj = vector<vector<int>>(n);

  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    if (!a[i]) a[i] = -1;
  }

  for (int i = 0; i < n - 1; ++i) {
    int x, y;
    cin >> x >> y;

    --x;
    --y;

    adj[x].push_back(y);
    adj[y].push_back(x);
  }

  dfs(0);
  dfs2(0);

  for (auto it : ans) {
    cout << it << ' ';
  }
  cout << '\n';
}