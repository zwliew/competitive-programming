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
  vector<int> p, r;
  DSU(int n) {
    p.resize(n);
    r.resize(n);
    iota(p.begin(), p.end(), 0);
  }
  void join(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v)
      return;
    if (r[u] == r[v])
      ++r[u];
    else if (r[u] < r[v])
      swap(u, v);
    p[v] = u;
  }
  int find(int u) { return p[u] == u ? u : p[u] = find(p[u]); }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int n, k;
  cin >> n >> k;
  DSU dsu(n);
  while (k--) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    dsu.join(a, b);
  }

  for (int i = 0; i < n; ++i) {
    int pos = n - i - 1;
    if (dsu.find(i) != dsu.find(pos)) {
      cout << "No";
      return 0;
    }
  }
  cout << "Yes";
}
