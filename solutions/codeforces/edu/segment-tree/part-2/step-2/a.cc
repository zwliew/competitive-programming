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

struct SegmentTree {
  vector<int64_t> added;
  vector<int64_t> mins;
  int n;

  SegmentTree(int _n) : n(_n) {
    added.resize(n * 4);
    mins.resize(n * 4);
  }

  void add(int l, int r, int x) { add(l, r, x, 0, 0, n); }

  void add(int l, int r, int x, int ti, int tl, int tr) {
    if (tl >= r || tr <= l)
      return;
    if (tl >= l && tr <= r) {
      added[ti] += x;
      mins[ti] += x;
      return;
    }
    push(ti);
    int tm = tl + (tr - tl) / 2;
    add(l, r, x, ti * 2 + 1, tl, tm);
    add(l, r, x, ti * 2 + 2, tm, tr);
    mins[ti] = min(mins[ti * 2 + 1], mins[ti * 2 + 2]);
  }

  void push(int ti) {
    mins[ti * 2 + 1] += added[ti];
    mins[ti * 2 + 2] += added[ti];
    added[ti * 2 + 1] += added[ti];
    added[ti * 2 + 2] += added[ti];
    added[ti] = 0;
  }

  int64_t minimum(int l, int r) { return minimum(l, r, 0, 0, n); }

  int64_t minimum(int l, int r, int ti, int tl, int tr) {
    if (tl >= r || tr <= l)
      return LLONG_MAX;
    if (tl >= l && tr <= r)
      return mins[ti];
    push(ti);
    int tm = tl + (tr - tl) / 2;
    return min(minimum(l, r, ti * 2 + 1, tl, tm),
               minimum(l, r, ti * 2 + 2, tm, tr));
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
      cout << t.minimum(l, r) << '\n';
    }
  }
}