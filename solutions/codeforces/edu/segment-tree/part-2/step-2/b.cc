/*
ID: zhaowei10
TASK:
LANG: C++14
*/
#include "bits/stdc++.h"

using namespace std;

#ifdef LOCAL
#include "../../_library/cc/debug.h"
#define FILE "test"
#else
#define debug(...) 0
#define FILE ""
#endif

const int mod = 1e9 + 7;

struct SegmentTree {
  int n;
  vector<int> sums, lazy;

  SegmentTree(int _n) : n(_n) {
    sums.assign(n * 4, 1);
    lazy.assign(n * 4, 1);
    build(0, 0, n);
  }

  void build(int ti, int tl, int tr) {
    if (tl == tr - 1)
      return;
    int tm = tl + (tr - tl) / 2;
    build(ti * 2 + 1, tl, tm);
    build(ti * 2 + 2, tm, tr);
    sums[ti] = (sums[ti * 2 + 1] + sums[ti * 2 + 2]) % mod;
  }

  void mult(int l, int r, int v) { mult(l, r, v, 0, 0, n); }

  void mult(int l, int r, int v, int ti, int tl, int tr) {
    if (tl >= r || tr <= l)
      return;
    if (l <= tl && tr <= r) {
      update(v, ti);
      return;
    }
    push(ti);
    int tm = tl + (tr - tl) / 2;
    mult(l, r, v, ti * 2 + 1, tl, tm);
    mult(l, r, v, ti * 2 + 2, tm, tr);
    sums[ti] = (sums[ti * 2 + 1] + sums[ti * 2 + 2]) % mod;
  }

  int sum(int l, int r) { return sum(l, r, 0, 0, n); }

  int sum(int l, int r, int ti, int tl, int tr) {
    if (tl >= r || tr <= l)
      return 0;
    if (l <= tl && tr <= r)
      return sums[ti];
    push(ti);
    int tm = tl + (tr - tl) / 2;
    return (sum(l, r, ti * 2 + 1, tl, tm) + sum(l, r, ti * 2 + 2, tm, tr)) %
           mod;
  }

  void update(int v, int ti) {
    sums[ti] = ((int64_t)sums[ti] * v) % mod;
    lazy[ti] = ((int64_t)lazy[ti] * v) % mod;
  }

  void push(int ti) {
    update(lazy[ti], ti * 2 + 1);
    update(lazy[ti], ti * 2 + 2);
    lazy[ti] = 1;
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
      t.mult(l, r, v);
    } else {
      cout << t.sum(l, r) << '\n';
    }
  }
}
