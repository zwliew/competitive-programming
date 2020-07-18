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
  vector<int> sum;
  int n;

  SegmentTree(int sz) : n(sz) { sum.resize(sz * 4, 0); }

  void set(int i, int x) { set(i, x, 0, 0, n - 1); }

  void set(int i, int x, int ti, int tl, int tr) {
    if (tl == tr) {
      sum[ti] = x;
      return;
    }
    int tm = tl + (tr - tl) / 2;
    if (i <= tm) {
      set(i, x, ti * 2 + 1, tl, tm);
    } else {
      set(i, x, ti * 2 + 2, tm + 1, tr);
    }
    sum[ti] = sum[ti * 2 + 1] + sum[ti * 2 + 2];
  }

  int query(int l, int r) { return query(l, r, 0, 0, n - 1); }

  int query(int l, int r, int ti, int tl, int tr) {
    if (tl > r || tr < l)
      return 0;
    if (tl >= l && tr <= r)
      return sum[ti];
    int tm = tl + (tr - tl) / 2;
    return query(l, r, ti * 2 + 1, tl, tm) +
           query(l, r, ti * 2 + 2, tm + 1, tr);
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
  vector<int> left(n, -1), ans(n);
  SegmentTree st(n * 2);
  for (int i = 0; i < n * 2; ++i) {
    int x;
    cin >> x;
    --x;
    if (left[x] != -1) {
      ans[x] = st.query(left[x], i);
      st.set(left[x], 1);
    } else {
      left[x] = i;
    }
  }

  for (int x : ans) {
    cout << x << ' ';
  }
}
