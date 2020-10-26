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

  int v, e, q;
  cin >> v >> e >> q;
  vector<vector<bool>> adj(v, vector<bool>(v)), tadj(v, vector<bool>(v)),
      comp(v, vector<bool>(v, true)), tcomp(v, vector<bool>(v, true));

  for (int i = 0; i < e; ++i) {
    int x, y;
    cin >> x >> y;
    adj[x][y] = true;
    tadj[y][x] = true;
    comp[x][y] = false;
    tcomp[y][x] = false;
  }

  while (q--) {
    int op;
    cin >> op;
    if (op == 1) {
      ++v;
      adj.resize(v);
      tadj.resize(v);
      comp.resize(v);
      tcomp.resize(v);
      for (int i = 0; i < v; ++i) {
        adj[i].resize(v);
        tadj[i].resize(v);
        comp[i].resize(v);
        tcomp[i].resize(v);
      }
      for (int i = 0; i < v; ++i) {
        comp[i][v - 1] = true;
        comp[v - 1][i] = true;
        tcomp[i][v - 1] = true;
        tcomp[v - 1][i] = true;
      }
    } else if (op == 2) {
      int x, y;
      cin >> x >> y;
      adj[x][y] = true;
      tadj[y][x] = true;
      comp[x][y] = false;
      tcomp[y][x] = false;
    } else if (op == 3) {
      int x;
      cin >> x;
      for (int i = 0; i < v; ++i) {
        adj[i][x] = false;
        adj[x][i] = false;
        tadj[i][x] = false;
        tadj[x][i] = false;
        comp[i][x] = true;
        comp[x][i] = true;
        tcomp[i][x] = true;
        tcomp[x][i] = true;
      }
    } else if (op == 4) {
      int x, y;
      cin >> x >> y;
      adj[x][y] = false;
      tadj[y][x] = false;
      comp[x][y] = true;
      tcomp[y][x] = true;
    } else if (op == 5) {
      swap(adj, tadj);
      swap(comp, tcomp);
    } else {
      swap(adj, comp);
      swap(tadj, tcomp);
    }
  }
  cout << v << "\n";
  const int mod = 1e9 + 7;
  for (int i = 0; i < v; ++i) {
    int deg = 0;
    int hash = 0;
    int pw = 1;
    for (int j = 0; j < v; ++j) {
      if (i != j && adj[i][j]) {
        ++deg;
        hash = (hash + ((int64_t)pw * j) % mod) % mod;
        pw = ((int64_t)pw * 7) % mod;
      }
    }
    cout << deg << " " << hash << '\n';
  }
}
