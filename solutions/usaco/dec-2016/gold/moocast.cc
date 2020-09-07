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
#define FILE "moocast"
#endif

struct DSU {
  vector<int> p;
  int sz;
  DSU(int n) {
    p.resize(n);
    iota(p.begin(), p.end(), 0);
    sz = n;
  }
  void join(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v)
      return;
    p[v] = u;
    --sz;
  }
  int find(int u) { return u == p[u] ? u : p[u] = find(p[u]); }
  bool same(int u, int v) { return find(u) == find(v); }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int n;
  cin >> n;
  vector<pair<int, int>> coords(n);
  for (int i = 0; i < n; ++i) {
    cin >> coords[i].first >> coords[i].second;
  }

  // Binary search on the distance and construct a new graph every time.
  // Time complexity: O(N^2). Binary search is actually log2(1e10) ~= 33.
  int64_t l = -1, r = 1e10;
  while (l < r - 1) {
    int64_t m = l + (r - l) / 2;
    DSU dsu(n);
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        int dx = coords[i].first - coords[j].first;
        int dy = coords[i].second - coords[j].second;
        if (dx * dx + dy * dy <= m) {
          dsu.join(i, j);
        }
      }
    }
    if (dsu.sz == 1) {
      r = m;
    } else {
      l = m;
    }
  }
  cout << r;

  // Alternative: Construct a minimum spanning tree with Kruskal's algorithm.
  // Time complexity: O(N^2)
  // vector<tuple<int, int, int>> edges;
  // for (int i = 0; i < n; ++i) {
  //   for (int j = i + 1; j < n; ++j) {
  //     int dx = coords[i].first - coords[j].first;
  //     int dy = coords[i].second - coords[j].second;
  //     int d = dx * dx + dy * dy;
  //     edges.emplace_back(d, i, j);
  //   }
  // }
  // sort(edges.begin(), edges.end());
  // DSU dsu(n);
  // int ans = 0;
  // for (int i = 0; i < edges.size() && dsu.sz > 1; ++i) {
  //   int d = get<0>(edges[i]);
  //   int u = get<1>(edges[i]);
  //   int v = get<2>(edges[i]);
  //   if (dsu.same(u, v)) {
  //     continue;
  //   }
  //   ans = d;
  //   dsu.join(u, v);
  // }
  // cout << ans;
}
