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
#define FILE "wormsort"
#endif

vector<vector<int>> adj(1'000'001);
vector<bool> vis(1'000'001);
int m, n;

void dfs(int u) {
  if (vis[u])
    return;
  vis[u] = true;
  if (u == m * n)
    return;
  for (int v : adj[u]) {
    dfs(v);
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  // If grid[r][c] == m, there is an edge from any position (i, j) where i * j
  // == r * c, to any position (a, b), where a * b == m
  cin >> m >> n;
  for (int i = 1; i <= m; ++i) {
    for (int j = 1; j <= n; ++j) {
      int x;
      cin >> x;
      adj[i * j].push_back(x);
    }
  }

  dfs(1);

  cout << (vis[m * n] ? "yes" : "no");
}

