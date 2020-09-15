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
// #include "bits/stdc++.h"

using namespace std;

#ifdef LOCAL
#include "../../_library/cc/debug.h"
#define FILE "test"
#else
#define debug(...) 0
#define FILE "cowjog"
#endif

struct Edge {
  int u, v;

  Edge(int _u, int _v) : u(_u), v(_v) {}
};

struct DSU {
  vector<int> p;

  DSU(int n) {
    p.resize(n);
    iota(p.begin(), p.end(), 0);
  }

  bool same(int u, int v) { return find(u) == find(v); }

  int find(int u) { return u == p[u] ? u : p[u] = find(p[u]); }

  void join(int u, int v) { p[find(v)] = find(u); }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  // Standard construction of a MST using Kruskal's algorithm
  int n, m;
  cin >> n >> m;
  vector<Edge> edges;
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    edges.emplace_back(u, v);
  }

  vector<int> ans;
  DSU dsu(n);
  for (int i = 0; i < m && ans.size() < n - 1; ++i) {
    auto& [u, v] = edges[i];
    if (dsu.same(u, v))
      continue;
    dsu.join(u, v);
    ans.emplace_back(i + 1);
  }

  if (ans.size() != n - 1) {
    cout << "Disconnected Graph";
  } else {
    for (int x : ans) {
      cout << x << '\n';
    }
  }
}
