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
#define FILE ""
#endif

vector<int> dp;  // dp[i] = longest path ending at node i
vector<vector<int>> adj;
int longest = 0;

void traverse(int u, int p) {
  vector<int> children;
  for (int v : adj[u]) {
    if (v != p) {
      traverse(v, u);
      children.push_back(dp[v]);
      dp[u] = max(dp[u], dp[v] + 1);
    }
  }

  longest = max(longest, dp[u]);

  if (children.size() >= 2) {
    sort(children.begin(), children.end());
    longest = max(longest, children[children.size() - 2] +
                               children[children.size() - 1] + 2);
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int n;
  cin >> n;
  adj.resize(n);
  dp.resize(n);
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  traverse(0, -1);
  cout << longest;
}
