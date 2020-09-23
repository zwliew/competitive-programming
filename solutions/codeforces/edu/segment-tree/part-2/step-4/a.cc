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
  int64_t sum = 0;
};

struct Lazy {
  int64_t val = 0;
  int type = 0;

  bool operator==(const Lazy& other) {
    return tie(val, type) == tie(other.val, other.type);
  }
};

const int ASSIGN = 2;
const int ADD = 1;

const Lazy NONE = {0, 0};
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
      update(INITIAL.sum, ASSIGN, ti, tl, tr);
      return;
    }
    int tm = tl + (tr - tl) / 2;
    build(ti * 2 + 1, tl, tm);
    build(ti * 2 + 2, tm, tr);
    vals[ti] = merge(vals[ti * 2 + 1], vals[ti * 2 + 2]);
  }

  Val merge(Val a, Val b) {
    Val res;
    res.sum = a.sum + b.sum;
    return res;
  }

  void push(int ti, int tl, int tr) {
    if (lazy[ti] == NONE)
      return;
    int tm = tl + (tr - tl) / 2;
    update(lazy[ti].val, lazy[ti].type, ti * 2 + 1, tl, tm);
    update(lazy[ti].val, lazy[ti].type, ti * 2 + 2, tm, tr);
    lazy[ti] = NONE;
  }

  void update(int64_t v, int type, int ti, int tl, int tr) {
    if (type == ASSIGN) {
      vals[ti].sum = 0;
      lazy[ti].val = 0;
    }
    vals[ti].sum += v * (tr - tl);
    lazy[ti].val += v;
    lazy[ti].type = ADD + (type == ASSIGN || lazy[ti].type == ASSIGN);
  }

  void modify(int l, int r, int v, bool assign) {
    modify(l, r, v, assign, 0, 0, n);
  }

  void modify(int l, int r, int v, bool assign, int ti, int tl, int tr) {
    if (tl >= r || tr <= l)
      return;
    if (tl >= l && tr <= r) {
      update(v, assign + 1, ti, tl, tr);
      return;
    }
    push(ti, tl, tr);
    int tm = tl + (tr - tl) / 2;
    modify(l, r, v, assign, ti * 2 + 1, tl, tm);
    modify(l, r, v, assign, ti * 2 + 2, tm, tr);
    vals[ti] = merge(vals[ti * 2 + 1], vals[ti * 2 + 2]);
  }

  int64_t query(int l, int r) { return query(l, r, 0, 0, n).sum; }

  Val query(int l, int r, int ti, int tl, int tr) {
    if (tl >= r || tr <= l)
      return NEUTRAL;
    if (tl >= l && tr <= r)
      return vals[ti];
    push(ti, tl, tr);
    int tm = tl + (tr - tl) / 2;
    return merge(query(l, r, ti * 2 + 1, tl, tm),
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
      t.modify(l, r, v, true);
    } else if (op == 2) {
      int v;
      cin >> v;
      t.modify(l, r, v, false);
    } else {
      cout << t.query(l, r) << "\n";
    }
  }
