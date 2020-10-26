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
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#ifdef LOCAL
#include "../../_library/cc/debug.h"
#define FILE "test"
#else
#define debug(...) 0
#define FILE ""
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<set<vector<int>>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
      int u, v, w;
      cin >> u >> v >> w;
      adj[u].insert({v, w});
      adj[v].insert({u, w});
    }

    for (int u = 1; u <= n; ++u) {
      if (adj[u].size() != 2)
        continue;
      auto e1 = *adj[u].begin();
      auto e2 = *next(adj[u].begin());
      adj[e1[0]].erase({u, e1[1]});
      adj[e1[0]].insert({e2[0], e1[1] + e2[1]});
      adj[e2[0]].erase({u, e2[1]});
      adj[e2[0]].insert({e1[0], e1[1] + e2[1]});
      adj[u].clear();
    }

    int cnt = 0;
    for (int u = 1; u <= n; ++u) {
      for (auto& e : adj[u]) {
        if (e[0] < u)
          continue;
        ++cnt;
      }
    }
    cout << cnt << "\n";
    for (int u = 1; u <= n; ++u) {
      for (auto& e : adj[u]) {
        if (e[0] < u)
          continue;
        cout << u << " " << e[0] << " " << e[1] << "\n";
      }
    }
    cout << "\n";
  }
}
