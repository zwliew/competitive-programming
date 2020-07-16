#include <vector>

struct Value {
  long long sum;
};

// Range sum Segment Tree
template <typename T>
struct SegmentTree {
  std::vector<Value> vals;
  int n;

  const Value NEUTRAL = {0};

  Value single(T x) { return {x}; }

  Value merge(Value a, Value b) { return {a.sum + b.sum}; }

  SegmentTree(std::vector<T>& a) {
    n = a.size();
    vals.resize(n * 4);
    build(a, 0, 0, n - 1);
  }

  void build(std::vector<T>& a, int ti, int tl, int tr) {
    if (tl == tr) {
      vals[ti] = single(a[tl]);
      return;
    }
    int tm = tl + (tr - tl) / 2;
    build(a, ti * 2 + 1, tl, tm);
    build(a, ti * 2 + 2, tm + 1, tr);
    vals[ti] = merge(vals[ti * 2 + 1], vals[ti * 2 + 2]);
  }

  void update(int i, T val) { update(i, val, 0, 0, n - 1); }

  void update(int i, T val, int ti, int tl, int tr) {
    if (tl == tr) {
      vals[ti] = single(val);
      return;
    }
    int tm = tl + (tr - tl) / 2;
    if (i <= tm) {
      update(i, val, ti * 2 + 1, tl, tm);
    } else {
      update(i, val, ti * 2 + 2, tm + 1, tr);
    }
    vals[ti] = merge(vals[ti * 2 + 1], vals[ti * 2 + 2]);
  }

  Value query(int l, int r) { return query(l, r, 0, 0, n - 1); }

  Value query(int l, int r, int ti, int tl, int tr) {
    if (tl > r || tr < l) {
      return NEUTRAL;
    }
    if (tl >= l && tr <= r) {
      return vals[ti];
    }
    int tm = tl + (tr - tl) / 2;
    return merge(query(l, r, ti * 2 + 1, tl, tm),
                 query(l, r, ti * 2 + 2, tm + 1, tr));
  }
};
