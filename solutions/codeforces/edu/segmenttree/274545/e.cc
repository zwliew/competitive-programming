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
  vector<int64_t> sums;
  int sz;

  SegmentTree(int n) : sz(n) { sums.assign(n * 4, 0); }

  void add(int l, int r, int x) { add(l, r, x, 0, 0, sz - 1); }

  void add(int l, int r, int x, int ti, int tl, int tr) {
    if (tl > r || tr < l)
      return;
    if (tl >= l && tr <= r) {
      sums[ti] += x;
      return;
    }
    int tm = tl + (tr - tl) / 2;
    add(l, r, x, ti * 2 + 1, tl, tm);
    add(l, r, x, ti * 2 + 2, tm + 1, tr);
  }

  int64_t get(int i) { return get(i, 0, 0, sz - 1); }

  int64_t get(int i, int ti, int tl, int tr) {
    if (tl == tr) {
      return sums[ti];
    }
    int tm = tl + (tr - tl) / 2;
    if (i <= tm) {
      return sums[ti] + get(i, ti * 2 + 1, tl, tm);
    }
    return sums[ti] + get(i, ti * 2 + 2, tm + 1, tr);
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
  SegmentTree st(n);
  while (m--) {
    int op;
    cin >> op;
    if (op == 1) {
      int l, r, v;
      cin >> l >> r >> v;
      st.add(l, r - 1, v);
    } else {
      int i;
      cin >> i;
      cout << st.get(i) << '\n';
    }
  }
}
