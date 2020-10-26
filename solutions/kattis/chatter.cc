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
  vector<bool> rep;
  DSU(int n) {
    p.resize(n);
    r.resize(n);
    sz.assign(n, 1);
    rep.assign(n, true);
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
    rep[v] = false;
  }
  int find(int u) { return u == p[u] ? u : p[u] = find(p[u]); }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int n, r, a, b, c;
  while (cin >> n >> r >> a >> b >> c) {
    DSU dsu(n);
    for (int i = 0; i < n; ++i) {
      int x = 0, y = 0;
      while (x == y) {
        r = (r * a + b) % c;
        x = r % n;
        r = (r * a + b) % c;
        y = r % n;
      }
      dsu.join(x, y);
    }
    int cnt = 0;
    map<int, int, greater<int>> sizes;
    for (int i = 0; i < n; ++i) {
      if (dsu.rep[i]) {
        sizes[dsu.sz[i]]++;
        ++cnt;
      }
    }
    cout << cnt << " ";
    for (auto& [k, v] : sizes) {
      cout << k;
      if (v > 1) {
        cout << "x" << v;
      }
      cout << " ";
    }
    cout << "\n";
  }
}
