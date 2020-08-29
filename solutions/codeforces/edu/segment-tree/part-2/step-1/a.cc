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
  vector<int64_t> vals;
  int n;

  SegmentTree(int _n) : n(_n) { vals.resize(n * 4); }

  void add(int i, int x) { add(i, x, 0, 0, n); }

  void add(int i, int x, int ti, int tl, int tr) {
    if (tl == tr - 1) {
      vals[ti] += x;
      return;
    }
    int tm = tl + (tr - tl) / 2;
    if (i < tm) {
      add(i, x, ti * 2 + 1, tl, tm);
    } else {
      add(i, x, ti * 2 + 2, tm, tr);
    }
    vals[ti] = vals[ti * 2 + 1] + vals[ti * 2 + 2];
  }

  int64_t sum(int i) { return sum(0, i + 1, 0, 0, n); }

  int64_t sum(int l, int r, int ti, int tl, int tr) {
    if (tl >= r || tr <= l)
      return 0;
    if (tl >= l && tr <= r)
      return vals[ti];
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
  SegmentTree t(n + 1);
  while (m--) {
    int op, l;
    cin >> op >> l;
    if (op == 1) {
      int r, v;
      cin >> r >> v;
      t.add(l, v);
      t.add(r, -v);
    } else {
      cout << t.sum(l) << '\n';
    }
  }
}
