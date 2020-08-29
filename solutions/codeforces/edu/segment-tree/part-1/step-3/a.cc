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

  void set(int i) { set(i, 0, 0, n); }

  void set(int i, int ti, int tl, int tr) {
    if (tl == tr - 1) {
      vals[ti] = 1;
      return;
    }
    int tm = tl + (tr - tl) / 2;
    if (i < tm) {
      set(i, ti * 2 + 1, tl, tm);
    } else {
      set(i, ti * 2 + 2, tm, tr);
    }
    vals[ti] = vals[ti * 2 + 1] + vals[ti * 2 + 2];
  }

  int sum(int l, int r) { return sum(l, r, 0, 0, n); }

  int sum(int l, int r, int ti, int tl, int tr) {
    if (tl >= r || tr <= l)
      return 0;
    if (tl >= l && tr <= r) {
      return vals[ti];
    }
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

  int n;
  cin >> n;
  SegmentTree t(n);
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    --x;
    cout << t.sum(x + 1, n) << ' ';
    t.set(x);
  }
}
