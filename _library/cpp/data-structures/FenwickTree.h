#include <vector>

// For updating point indices, querying range sums
template <typename T>
struct PURQFenwickTree {
  std::vector<T> t;

  PURQFenwickTree(size_t n) : t(n + 1) {}

  void update(int idx, T val) {
    for (++idx; idx < t.size(); idx += idx & -idx) {
      t[idx] += val;
    }
  }

  T query(int idx) {
    T res = 0;
    for (++idx; idx; idx -= idx & -idx) {
      res += t[idx];
    }
    return res;
  }
};

// For updating range indices, querying point indices
template <typename T>
struct RUPQFenwickTree {
  std::vector<T> t;

  RUPQFenwickTree(size_t n) : t(n + 1) {}

  void _update(int idx, T val) {
    for (++idx; idx < t.size(); idx += idx & -idx) {
      t[idx] += val;
    }
  }

  void update(int l, int r, T val) {
    _update(l, val);
    _update(r + 1, -val);
  }

  T query(int idx) {
    T res = 0;
    for (++idx; idx; idx -= idx & -idx) {
      res += t[idx];
    }
    return res;
  }
};

// For updating range indices, querying range sums
template <typename T>
struct RURQFenwickTree {
  std::vector<T> t1, t2;

  RURQFenwickTree(size_t n) {
    t1.assign(n + 1, 0);
    t2.assign(n + 1, 0);
  }

  void _update(std::vector<T> &t, int idx, T val) {
    for (++idx; idx < t.size(); idx += idx & -idx) {
      t[idx] += val;
    }
  }

  void update(int l, int r, T val) {
    _update(t1, l, val);
    _update(t1, r + 1, -val);
    _update(t2, l, val * (l - 1));
    _update(t2, r + 1, -val * r);
  }

  T _query(std::vector<T> &t, int idx) {
    T res = 0;
    for (++idx; idx; idx -= idx & -idx) {
      res += t[idx];
    }
    return res;
  }

  T _query(int idx) { return _query(t1, idx) * idx - _query(t2, idx); }

  T query(int l, int r) { return _query(r) - _query(l - 1); }
};