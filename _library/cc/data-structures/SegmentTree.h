#include <vector>

// Range sum Segment Tree
template <typename T>
struct SegmentTree {
  std::vector<T> sums;
  int n;

  SegmentTree(std::vector<T>& a) {
    n = a.size();
    sums.assign(n * 4, 0);
    build(a, 0, 0, n - 1);
  }

  void build(std::vector<T>& a, int ti, int tl, int tr) {
    if (tl == tr) {
      sums[ti] = a[tl];
      return;
    }
    int tm = tl + (tr - tl) / 2;
    build(a, ti * 2 + 1, tl, tm);
    build(a, ti * 2 + 2, tm + 1, tr);
    compute(ti);
  }

  void update(int i, T val) { update(i, val, 0, 0, n - 1); }

  void update(int i, T val, int ti, int tl, int tr) {
    if (tl == tr) {
      sums[ti] = val;
      return;
    }
    int tm = tl + (tr - tl) / 2;
    if (i <= tm) {
      update(i, val, ti * 2 + 1, tl, tm);
    } else {
      update(i, val, ti * 2 + 2, tm + 1, tr);
    }
    compute(ti);
  }

  void compute(int ti) { sums[ti] = sums[ti * 2 + 1] + sums[ti * 2 + 2]; }

  T query(int l, int r) { return query(l, r, 0, 0, n - 1); }

  T query(int l, int r, int ti, int tl, int tr) {
    if (tl > r || tr < l) {
      return 0;
    }
    if (tl >= l && tr <= r) {
      return sums[ti];
    }
    int tm = tl + (tr - tl) / 2;
    return query(l, r, ti * 2 + 1, tl, tm) +
           query(l, r, ti * 2 + 2, tm + 1, tr);
  }
};
