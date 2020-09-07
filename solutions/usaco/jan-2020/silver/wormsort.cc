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

struct DSU {
  vector<int> p;
  DSU(int n) {
    p.resize(n);
    iota(p.begin(), p.end(), 0);
  }
  void join(int u, int v) { p[find(v)] = find(u); }
  int find(int u) { return u == p[u] ? u : p[u] = find(p[u]); }
  bool same(int u, int v) { return find(u) == find(v); }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int n, m;
  cin >> n >> m;
  vector<int> p(n);
  bool needed = false;
  for (int i = 0; i < n; ++i) {
    cin >> p[i];
    --p[i];
    if (p[i] != i) {
      needed = true;
    }
  }

  if (!needed) {
    cout << -1;
    return 0;
  }

  vector<tuple<int, int, int>> edges(m);
  for (int i = 0; i < m; ++i) {
    cin >> get<0>(edges[i]) >> get<1>(edges[i]) >> get<2>(edges[i]);
    --get<0>(edges[i]);
    --get<1>(edges[i]);
  }

  int l = 1, r = 1e9 + 1;
  while (l < r - 1) {
    int mid = l + (r - l) / 2;
    DSU dsu(n);
    for (int i = 0; i < m; ++i) {
      if (get<2>(edges[i]) >= mid) {
        dsu.join(get<0>(edges[i]), get<1>(edges[i]));
      }
    }

    bool ok = true;
    for (int i = 0; i < n && ok; ++i) {
      if (!dsu.same(i, p[i])) {
        ok = false;
      }
    }

    if (ok) {
      l = mid;
    } else {
      r = mid;
    }
  }

  cout << l;
}
