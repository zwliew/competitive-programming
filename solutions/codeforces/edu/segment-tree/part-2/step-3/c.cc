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

struct Val {
  int mx = 0;
};

struct Lazy {
  int add = 0;

  bool operator==(const Lazy& other) { return add == other.add; }
};

const Lazy NONE = {0};
const Val NEUTRAL = {0};
const Val INITIAL = {0};

struct SegmentTree {
  int n;
  vector<Val> vals;
  vector<Lazy> lazy;

  SegmentTree(int _n) : n(_n) {
    vals.assign(n * 4, INITIAL);
    lazy.assign(n * 4, NONE);
    build(0, 0, n);
  }

  void build(int ti, int tl, int tr) {
    if (tl == tr - 1) {
      update(INITIAL.mx, ti);
      return;
    }
    int tm = tl + (tr - tl) / 2;
    build(ti * 2 + 1, tl, tm);
    build(ti * 2 + 2, tm, tr);
    vals[ti] = merge(vals[ti * 2 + 1], vals[ti * 2 + 2]);
  }

  Val merge(Val a, Val b) {
    Val res;
    res.mx = max(a.mx, b.mx);
    return res;
  }

  void push(int ti) {
    if (lazy[ti] == NONE)
      return;
    update(lazy[ti].add, ti * 2 + 1);
    update(lazy[ti].add, ti * 2 + 2);
    lazy[ti] = NONE;
  }

  void update(int v, int ti) {
    vals[ti].mx += v;
    lazy[ti].add += v;
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
    vals[ti] = merge(vals[ti * 2 + 1], vals[ti * 2 + 2]);
  }

  int query(int x, int l) { return query(x, l, 0, 0, n); }

  int query(int x, int l, int ti, int tl, int tr) {
    if (tr <= l || vals[ti].mx < x)
      return -1;
    if (tl == tr - 1)
      return tl;
    push(ti);
    int tm = tl + (tr - tl) / 2;
    int res = query(x, l, ti * 2 + 1, tl, tm);
    if (res == -1) {
      res = query(x, l, ti * 2 + 2, tm, tr);
    }
    return res;
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
    int op;
    cin >> op;
    if (op == 1) {
      int l, r, v;
      cin >> l >> r >> v;
      t.modify(l, r, v);
    } else {
      int x, l;
      cin >> x >> l;
      cout << t.query(x, l) << '\n';
    }
  }
}
