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

int ans = 0;
void dfs(vector<vector<pair<int, int>>>& adj, int k, int p, int u) {
  ++ans;
  for (auto& v : adj[u]) {
    if (p != v.first && v.second >= k) {
      dfs(adj, k, u, v.first);
    }
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int n, q;
  cin >> n >> q;
  vector<vector<pair<int, int>>> adj(n);
  for (int i = 0; i < n - 1; ++i) {
    int u, v, r;
    cin >> u >> v >> r;
    --u;
    --v;
    adj[u].emplace_back(v, r);
    adj[v].emplace_back(u, r);
  }

  while (q--) {
    int k, v;
    cin >> k >> v;
    --v;
    ans = 0;
    dfs(adj, k, -1, v);
    cout << ans - 1 << '\n';
  }
}
