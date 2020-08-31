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
  vector<int64_t> sums, lazy;

  SegmentTree(int _n) : n(_n) {
    sums.resize(n * 4);
    lazy.resize(n * 4);
  }

  void add(int l, int r, int v) { add(l, r, v, 0, 0, n); }

  void add(int l, int r, int v, int ti, int tl, int tr) {
    if (tl >= r || tr <= l)
      return;
    if (tl >= l && tr <= r) {
      update(v, ti, tl, tr);
      return;
    }
    push(ti, tl, tr);
    int tm = tl + (tr - tl) / 2;
    add(l, r, v, ti * 2 + 1, tl, tm);
    add(l, r, v, ti * 2 + 2, tm, tr);
    sums[ti] = sums[ti * 2 + 1] + sums[ti * 2 + 2];
  }

  void update(int v, int ti, int tl, int tr) {
    sums[ti] += (int64_t)v * (tr - tl);
    lazy[ti] += v;
  }

  void push(int ti, int tl, int tr) {
    int tm = tl + (tr - tl) / 2;
    update(lazy[ti], ti * 2 + 1, tl, tm);
    update(lazy[ti], ti * 2 + 2, tm, tr);
    lazy[ti] = 0;
  }

  int64_t sum(int l, int r) { return sum(l, r, 0, 0, n); }

  int64_t sum(int l, int r, int ti, int tl, int tr) {
    if (tl >= r || tr <= l)
      return 0;
    if (tl >= l && tr <= r)
      return sums[ti];
    push(ti, tl, tr);
    int tm = tl + (tr - tl) / 2;
    return sum(l, r, ti * 2 + 1, tl, tm) + sum(l, r, ti * 2 + 2, tm, tr);
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
      t.add(l, r, v);
    } else {
      cout << t.sum(l, r) << '\n';
    }
  }
}
