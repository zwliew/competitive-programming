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
#define FILE ""
#endif

struct SegmentTree {
  vector<int64_t> val, lazy;
  int n;

  SegmentTree(int _n) : n(_n) {
    val.resize(n * 4);
    lazy.resize(n * 4);
  }

  void add(int l, int r, int64_t x) { add(l, r, x, 0, 0, n); }

  void add(int l, int r, int64_t x, int ti, int tl, int tr) {
    if (l >= tr || r <= tl)
      return;
    if (tl >= l && tr <= r) {
      modify(x, ti, tl, tr);
      return;
    }
    push(ti, tl, tr);
    int tm = tl + (tr - tl) / 2;
    add(l, r, x, ti * 2 + 1, tl, tm);
    add(l, r, x, ti * 2 + 2, tm, tr);
    val[ti] = val[ti * 2 + 1] + val[ti * 2 + 2];
  }

  void modify(int64_t x, int ti, int tl, int tr) {
    val[ti] += x * (tr - tl);
    lazy[ti] += x;
  }

  void push(int ti, int tl, int tr) {
    if (lazy[ti]) {
      int tm = tl + (tr - tl) / 2;
      modify(lazy[ti], ti * 2 + 1, tl, tm);
      modify(lazy[ti], ti * 2 + 2, tm, tr);
      lazy[ti] = 0;
    }
  }

  int64_t query(int l, int r) { return query(l, r, 0, 0, n); }

  int64_t query(int l, int r, int ti, int tl, int tr) {
    if (tl >= r || tr <= l)
      return 0;
    if (tl >= l && tr <= r)
      return val[ti];
    push(ti, tl, tr);
    int tm = tl + (tr - tl) / 2;
    return query(l, r, ti * 2 + 1, tl, tm) + query(l, r, ti * 2 + 2, tm, tr);
  }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  // Use a difference array and query a single index by taking prefix sums.
  int n, m;
  cin >> n >> m;
  SegmentTree t(n);
  while (m--) {
    int op;
    cin >> op;
    if (op == 1) {
      int l, r;
      int64_t a, d;
      cin >> l >> r >> a >> d;
      --l;
      t.add(l, l + 1, a);
      t.add(l + 1, r, d);
      t.add(r, r + 1, -a - d * (r - l - 1));
    } else {
      int i;
      cin >> i;
      --i;
      cout << t.query(0, i + 1) << "\n";
    }
  }
}
