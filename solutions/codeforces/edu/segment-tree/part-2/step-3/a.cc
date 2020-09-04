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
  int64_t mx = 0;
  int64_t suf = 0;
  int64_t pre = 0;
  int64_t sum = 0;
};

const int NONE = 1e9 + 1;
const Val NEUTRAL = {0, 0, 0, 0};

struct SegmentTree {
  int n;
  vector<Val> vals;
  vector<int> lazy;

  SegmentTree(int _n) : n(_n) {
    vals.resize(n * 4);
    lazy.assign(n * 4, NONE);
  }

  Val merge(Val a, Val b) {
    Val res;
    res.sum = a.sum + b.sum;
    res.pre = max(a.pre, a.sum + b.pre);
    res.suf = max(b.suf, b.sum + a.suf);
    res.mx = max({a.mx, b.mx, a.suf + b.pre});
    return res;
  }

  void push(int ti, int tl, int tr) {
    if (lazy[ti] == NONE)
      return;
    int tm = tl + (tr - tl) / 2;
    update(lazy[ti], ti * 2 + 1, tl, tm);
    update(lazy[ti], ti * 2 + 2, tm, tr);
    lazy[ti] = NONE;
  }

  void update(int v, int ti, int tl, int tr) {
    vals[ti].sum = (int64_t)v * (tr - tl);
    vals[ti].mx = vals[ti].suf = vals[ti].pre = max((int64_t)0, vals[ti].sum);
    lazy[ti] = v;
  }

  void modify(int l, int r, int v) { modify(l, r, v, 0, 0, n); }

  void modify(int l, int r, int v, int ti, int tl, int tr) {
    if (tl >= r || tr <= l)
      return;
    if (tl >= l && tr <= r) {
      update(v, ti, tl, tr);
      return;
    }
    push(ti, tl, tr);
    int tm = tl + (tr - tl) / 2;
    modify(l, r, v, ti * 2 + 1, tl, tm);
    modify(l, r, v, ti * 2 + 2, tm, tr);
    vals[ti] = merge(vals[ti * 2 + 1], vals[ti * 2 + 2]);
  }

  int64_t query(int l, int r) { return query(l, r, 0, 0, n).mx; }

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
    int l, r, v;
    cin >> l >> r >> v;
    t.modify(l, r, v);
    cout << t.query(0, n) << '\n';
  }
}
