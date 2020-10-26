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

struct DSU {
  vector<int> p, r, sz;
  DSU(int n) {
    p.resize(n);
    r.resize(n);
    sz.assign(n, 1);
    iota(p.begin(), p.end(), 0);
  }
  void join(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v)
      return;
    if (r[u] == r[v]) {
      ++r[u];
    } else if (r[u] < r[v]) {
      swap(u, v);
    }
    p[v] = u;
    sz[u] += sz[v];
  }
  int find(int u) { return u == p[u] ? u : p[u] = find(p[u]); }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  const int M = 500001;
  int n;
  cin >> n;
  DSU dsu(M);
  int total = 0;
  while (n--) {
    int m;
    cin >> m;
    int cnt = 0;
    vector<int> ingredients(m);
    unordered_set<int> accounted;
    for (auto& x : ingredients) {
      cin >> x;
      int p = dsu.find(x);
      if (!accounted.count(p)) {
        cnt += dsu.sz[p];
        accounted.insert(p);
      }
    }
    if (cnt == m) {
      for (int i = 1; i < m; ++i) {
        dsu.join(ingredients[i], ingredients[i - 1]);
      }
      ++total;
    }
  }
  cout << total;
}
