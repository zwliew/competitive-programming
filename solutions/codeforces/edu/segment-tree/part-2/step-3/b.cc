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
  int len = 0;
  int sum = 0;
};

struct Lazy {
  bool inverted = false;
};

const bool NONE = false;
const Val NEUTRAL = {0, 0};

struct SegmentTree {
  int n;
  vector<Val> vals;
  vector<Lazy> lazy;

  SegmentTree(int _n) : n(_n) {
    vals.resize(n * 4);
    lazy.resize(n * 4);
    build(0, 0, n);
  }

  void build(int ti, int tl, int tr) {
    if (tl == tr - 1) {
      vals[ti].len = 1;
      return;
    }
    int tm = tl + (tr - tl) / 2;
    build(ti * 2 + 1, tl, tm);
    build(ti * 2 + 2, tm, tr);
    vals[ti] = merge(vals[ti * 2 + 1], vals[ti * 2 + 2]);
  }

  Val merge(Val a, Val b) {
    Val res;
    res.len = a.len + b.len;
    res.sum = a.sum + b.sum;
    return res;
  }

  void push(int ti, int tl, int tr) {
    if (lazy[ti].inverted == NONE)
      return;
    int tm = tl + (tr - tl) / 2;
    update(ti * 2 + 1);
    update(ti * 2 + 2);
    lazy[ti].inverted = NONE;
  }

  void update(int ti) {
    vals[ti].sum = vals[ti].len - vals[ti].sum;
    lazy[ti].inverted = !lazy[ti].inverted;
  }

  void modify(int l, int r) { modify(l, r, 0, 0, n); }

  void modify(int l, int r, int ti, int tl, int tr) {
    if (tl >= r || tr <= l)
      return;
    if (tl >= l && tr <= r) {
      update(ti);
      return;
    }
    push(ti, tl, tr);
    int tm = tl + (tr - tl) / 2;
    modify(l, r, ti * 2 + 1, tl, tm);
    modify(l, r, ti * 2 + 2, tm, tr);
    vals[ti] = merge(vals[ti * 2 + 1], vals[ti * 2 + 2]);
  }

  int query(int k) { return query(k, 0, 0, n); }

  int query(int k, int ti, int tl, int tr) {
    if (tl == tr - 1)
      return tl;
    push(ti, tl, tr);
    int tm = tl + (tr - tl) / 2;
    if (vals[ti * 2 + 1].sum > k) {
      return query(k, ti * 2 + 1, tl, tm);
    }
    return query(k - vals[ti * 2 + 1].sum, ti * 2 + 2, tm, tr);
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
      int l, r;
      cin >> l >> r;
      t.modify(l, r);
    } else {
      int k;
      cin >> k;
      cout << t.query(k) << '\n';
    }
  }
}
