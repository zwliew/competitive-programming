#include <vector>

// Useful for computing range queries in general
// First element greater than x, First array prefix greater than x
struct SegmentTree {
  std::vector<long long> t;
  long long n = -1;

  SegmentTree(long long cn) {
    t = std::vector<long long>(n * 4);
    n = cn;
  }

  void build(std::vector<long long> &a, long long v, long long tl,
             long long tr) {
    if (tl == tr) {
      t[v] = a[tl];
    } else {
      long long mid = tl + (tr - tl) / 2;
      build(a, v * 2, tl, tm);
      build(a, v * 2 + 1, tm + 1, tr);
      t[v] = t[v * 2] + t[v * 2 + 1];
    }
  }

  void update(long long v, long long tl, long long tr, long long pos,
              long long val) {
    if (tl == tr) {
      t[v] += val;
    } else {
      long long tm = tl + (tr - tl) / 2;
      if (pos <= tm) {
        update(v * 2, tl, tm, pos, val);
      } else {
        update(v * 2 + 1, tm + 1, tr, pos, val);
      }
      t[v] = t[v * 2] + t[v * 2 + 1];
    }
  }

  long long query(long long v, long long tl, long long tr, long long l,
                  long long r) {
    if (tl == l && tr == r) return t[v];
    long long tm = tl + (tr - tl) / 2;
    if (r <= tm) {
      return query(v * 2, tl, tm, l, r);
    } else if (l > tm) {
      return query(v * 2 + 1, tm + 1, tr, l, r);
    } else {
      return query(v * 2, tl, tm, l, tm) +
             query(v * 2 + 1, tm + 1, tr, tm + 1, r);
    }
  }
}
