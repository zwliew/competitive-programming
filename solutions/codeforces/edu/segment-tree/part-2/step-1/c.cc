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
#define FILE "socdist"
#endif

struct SegmentTree {
  vector<int> vals;
  int n;

  SegmentTree(int _n) : n(_n) { vals.resize(n * 4); }

  void assign(int l, int r, int x) { assign(l, r, x, 0, 0, n); }

  void assign(int l, int r, int x, int ti, int tl, int tr) {
    if (tl >= r || tr <= l)
      return;
    if (tl >= l && tr <= r) {
      vals[ti] = x;
      return;
    }
    propagate(ti);
    int tm = tl + (tr - tl) / 2;
    assign(l, r, x, ti * 2 + 1, tl, tm);
    assign(l, r, x, ti * 2 + 2, tm, tr);
  }

  void propagate(int ti) {
    if (vals[ti] != INT_MAX) {
      vals[ti * 2 + 1] = vals[ti * 2 + 2] = vals[ti];
      vals[ti] = INT_MAX;
    }
  }

  int get(int i) { return get(i, 0, 0, n); }

  int get(int i, int ti, int tl, int tr) {
    if (tl == tr - 1) {
      return vals[ti];
    }
    propagate(ti);
    int tm = tl + (tr - tl) / 2;
    if (i < tm) {
      return get(i, ti * 2 + 1, tl, tm);
    }
    return get(i, ti * 2 + 2, tm, tr);
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
    int op, l, r, v;
    cin >> op >> l;
    if (op == 1) {
      cin >> r >> v;
      t.assign(l, r, v);
    } else {
      cout << t.get(l) << '\n';
    }
  }
}
