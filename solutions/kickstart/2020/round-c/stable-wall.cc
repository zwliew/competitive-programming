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

vector<unordered_set<int>> adj(26);
vector<int> vis(26);
bool ok = true;
vector<int> order;
void topoSort(int u) {
  vis[u] = 1;
  for (int v : adj[u]) {
    if (vis[v] == 1) {
      ok = false;
      return;
    }
    if (!vis[v]) {
      topoSort(v);
    }
  }
  vis[u] = 2;
  order.push_back(u);
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  // Construct a directed graph using the required ordering from bottom to top
  // and check that the graph is acyclic
  int t;
  cin >> t;
  for (int ti = 1; ti <= t; ++ti) {
    cout << "Case #" << ti << ": ";

    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        cin >> grid[i][j];
      }
    }

    adj.assign(26, unordered_set<int>());
    for (int i = 1; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (grid[i][j] != grid[i - 1][j])
          adj[grid[i][j] - 'A'].insert(grid[i - 1][j] - 'A');
      }
    }

    ok = true;
    vis.assign(26, false);
    order.clear();
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (!vis[grid[i][j] - 'A']) {
          topoSort(grid[i][j] - 'A');
        }
      }
    }

    if (!ok) {
      cout << "-1\n";
    } else {
      for (int i = (int)order.size() - 1; i >= 0; --i) {
        cout << (char)(order[i] + 'A');
      }
      cout << '\n';
    }
  }
}
