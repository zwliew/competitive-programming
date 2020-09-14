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
#define FILE "berries"
#endif

struct DSU {
  vector<int> p;
  DSU(int n) {
    p.resize(n);
    iota(p.begin(), p.end(), 0);
  }
  void join(int u, int v) { p[find(v)] = find(u); }
  int find(int u) { return u == p[u] ? u : p[u] = find(p[u]); }
};

array<vector<int>, 100000> adjt;
array<int, 100000> dist, ans, adj;
DSU dsu(100000);

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  // MSSP on a bunch of disconnected DAGs.
  // Use disjoint sets to find the endpoint for each vertex.
  int n;
  cin >> n;

  fill(ans.begin(), ans.end(), -1);
  fill(dist.begin(), dist.end(), INT_MAX);

  queue<int> q;
  for (int i = 0; i < n; ++i) {
    cin >> adj[i];
    if (adj[i] != -1) {
      adjt[adj[i]].push_back(i);
    } else {
      q.emplace(i);
      dist[i] = 0;
    }
  }

  while (q.size()) {
    int u = q.front();
    q.pop();

    int p = dsu.find(u);
    if (adjt[u].empty()) {
      if (ans[p] == -1 || dist[u] < dist[ans[p]] ||
          (dist[u] == dist[ans[p]] && u < ans[p])) {
        ans[p] = u;
      }
    }

    for (int v : adjt[u]) {
      if (dist[v] > dist[u] + 1) {
        dsu.join(u, v);
        dist[v] = dist[u] + 1;
        q.emplace(v);
      }
    }
  }

  int a;
  cin >> a;
  while (a--) {
    int d;
    cin >> d;
    cout << ans[dsu.find(d)] << '\n';
  }
}
