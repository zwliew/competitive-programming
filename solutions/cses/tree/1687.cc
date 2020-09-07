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
#define FILE "mootube"
#endif

vector<vector<int>> adj;
vector<vector<int>> up;
int l;
void dfs(int u, int p) {
  up[u][0] = p;
  for (int i = 1; i <= l && up[u][i - 1] != -1; ++i) {
    up[u][i] = up[up[u][i - 1]][i - 1];
  }
  for (int v : adj[u]) {
    if (v != p) {
      dfs(v, u);
    }
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  // Use binary lifting to compute all ancestors which are 2^k above the current
  // node for every node.
  int n, q;
  cin >> n >> q;
  adj.resize(n);
  l = ceil(log2(n));
  up.assign(n, vector<int>(l + 1, -1));
  for (int i = 1; i < n; ++i) {
    int p;
    cin >> p;
    --p;
    adj[p].push_back(i);
    adj[i].push_back(p);
  }

  dfs(0, -1);

  while (q--) {
    int x, k;
    cin >> x >> k;
    --x;
    int i = 0;
    while (k && x != -1) {
      if (k & 1) {
        x = up[x][i];
      }
      k >>= 1;
      ++i;
    }
    cout << (x == -1 ? x : x + 1) << '\n';
  }
}
