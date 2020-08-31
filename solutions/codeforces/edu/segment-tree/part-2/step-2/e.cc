/*
ID: zhaowei10
TASK:
LANG: C++14
*/
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <cmath>
#include <deque>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
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
  int n;
  vector<int> vals, lazy;

  SegmentTree(int _n) : n(_n) {
    vals.resize(n * 4);
    lazy.resize(n * 4);
  }

  void modify(int l, int r, int v) { modify(l, r, v, 0, 0, n); }

  void modify(int l, int r, int v, int ti, int tl, int tr) {
    if (tl >= r || tr <= l)
      return;
    if (tl >= l && tr <= r) {
      update(v, ti);
      return;
    }
    push(ti);
    int tm = tl + (tr - tl) / 2;
    modify(l, r, v, ti * 2 + 1, tl, tm);
    modify(l, r, v, ti * 2 + 2, tm, tr);
    vals[ti] = min(vals[ti * 2 + 1], vals[ti * 2 + 2]);
  }

  void update(int v, int ti) {
    vals[ti] = v;
    lazy[ti] = v;
  }

  void push(int ti) {
    if (lazy[ti] == -1)
      return;
    update(lazy[ti], ti * 2 + 1);
    update(lazy[ti], ti * 2 + 2);
    lazy[ti] = -1;
  }

  int64_t query(int l, int r) { return query(l, r, 0, 0, n); }

  int64_t query(int l, int r, int ti, int tl, int tr) {
    if (tl >= r || tr <= l)
      return INT_MAX;
    if (tl >= l && tr <= r)
      return vals[ti];
    push(ti);
    int tm = tl + (tr - tl) / 2;
    return min(query(l, r, ti * 2 + 1, tl, tm),
               query(l, r, ti * 2 + 2, tm, tr));
  }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int n, m;
  cin >> n >> m;
  SegmentTree t(n);
  while (m--) {
    int op, l, r;
    cin >> op >> l >> r;
    if (op == 1) {
      int v;
      cin >> v;
      t.modify(l, r, v);
    } else {
      cout << t.query(l, r) << '\n';
    }
  }
}
