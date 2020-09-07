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
#define FILE "maxflow"
#endif

vector<vector<int>> adj;
vector<unordered_set<int>> c;
vector<int> ans;

void dfs(int u, int p) {
  for (int v : adj[u]) {
    if (v != p) {
      dfs(v, u);
      if (c[u].size() < c[v].size()) {
        swap(c[u], c[v]);
      }
      for (int x : c[v]) {
        c[u].insert(x);
      }
    }
  }
  ans[u] = c[u].size();
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  // Merge sets efficiently by swapping the contents of the sets when the size
  // of the parent's set is smaller than the size of the child's set
  int n;
  cin >> n;
  c.resize(n);
  adj.resize(n);
  ans.resize(n);
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    c[i].insert(x);
  }
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  dfs(0, -1);
  for (int x : ans) {
    cout << x << ' ';
  }
}
