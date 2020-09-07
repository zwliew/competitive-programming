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

vector<map<int, int64_t>> c;
vector<vector<int>> adj;
vector<int64_t> sum;
vector<int> mx;

void dfs(int u, int p) {
  for (int v : adj[u]) {
    if (v != p) {
      dfs(v, u);

      if (c[u].size() < c[v].size()) {
        swap(c[u], c[v]);
        mx[u] = mx[v];
        sum[u] = sum[v];
      }

      for (auto& [k, x] : c[v]) {
        c[u][k] += x;
        if (c[u][k] > mx[u]) {
          sum[u] = k;
          mx[u] = c[u][k];
        } else if (c[u][k] == mx[u]) {
          sum[u] += k;
        }
      }
    }
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  // Do small-to-large merging of the frequencies of colors for each node on the
  // tree.
  int n;
  cin >> n;

  c.resize(n);
  adj.resize(n);
  sum.resize(n);
  mx.resize(n);

  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    c[i][x] = 1;
    sum[i] = x;
    mx[i] = 1;
  }

  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  dfs(0, -1);

  for (auto x : sum) {
    cout << x << ' ';
  }
}
