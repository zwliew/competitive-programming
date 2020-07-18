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

struct Value {
  int64_t sum;
};

struct SegmentTree {
  vector<Value> vals;
  int sz;

  SegmentTree(vector<int>& a) {
    sz = a.size();
    vals = vector<Value>(sz * 4);
    build(a, 1, 0, sz - 1);
  }

  void build(vector<int>& a, int ti, int tl, int tr) {
    if (tl == tr) {
      vals[ti] = {a[tl]};
      return;
    }
    int tm = tl + (tr - tl) / 2;
    build(a, ti * 2, tl, tm);
    build(a, ti * 2 + 1, tm + 1, tr);
    vals[ti] = merge(vals[ti * 2], vals[ti * 2 + 1]);
  }

  Value merge(Value a, Value b) { return {a.sum + b.sum}; }

  void set(int i, int x) { set(i, x, 1, 0, sz - 1); }

  void set(int i, int x, int ti, int tl, int tr) {
    if (tl == tr) {
      vals[ti] = {x};
      return;
    }
    int tm = tl + (tr - tl) / 2;
    if (i <= tm) {
      set(i, x, ti * 2, tl, tm);
    } else {
      set(i, x, ti * 2 + 1, tm + 1, tr);
    }
    vals[ti] = merge(vals[ti * 2], vals[ti * 2 + 1]);
  }

  Value query(int l, int r) { return query(l, r, 1, 0, sz - 1); }

  Value query(int l, int r, int ti, int tl, int tr) {
    if (tl > r || tr < l)
      return {0};
    if (l <= tl && tr <= r)
      return vals[ti];
    int tm = tl + (tr - tl) / 2;
    return merge(query(l, r, ti * 2, tl, tm),
                 query(l, r, ti * 2 + 1, tm + 1, tr));
  }
};

struct FenwickTree {
  vector<int64_t> t;
  int sz;

  FenwickTree(vector<int>& a) {
    sz = a.size();
    t.assign(sz + 1, 0);
    for (int i = 0; i < a.size(); ++i) {
      add(i, a[i]);
    }
  }

  void add(int i, int x) {
    for (++i; i <= sz; i += i & -i) {
      t[i] += x;
    }
  }

  void set(int i, int x) {
    int64_t cur = query(i) - (i > 0 ? query(i - 1) : 0);
    add(i, -cur);
    add(i, x);
  }

  int64_t query(int r) {
    int64_t res = 0;
    for (++r; r; r -= r & -r) {
      res += t[r];
    }
    return res;
  }

  int64_t query(int l, int r) { return query(r) - (l > 0 ? query(l - 1) : 0); }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    if (i % 2) {
      a[i] = -a[i];
    }
  }
  FenwickTree t(a);
  int m;
  cin >> m;
  while (m--) {
    int op, i, j;
    cin >> op >> i >> j;
    --i;
    if (op) {
      --j;
      cout << t.query(i, j) * (i % 2 ? -1 : 1) << '\n';
    } else {
      t.set(i, j * (i % 2 ? -1 : 1));
    }
  }
}
