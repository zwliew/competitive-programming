#include <vector>
// Useful for computing prefix or range sums efficiently
struct FenwickTree {
  std::vector<long long> b1, b2;
  long long n;

  FenwickTree(long long n) {
    this->n = n + 1;
    b1.assign(this->n, 0);
    b2.assign(this->n, 0);
  }

  FenwickTree(std::vector<long long> &a) : FenwickTree(a.size()) {
    for (long long i = 0; i < a.size(); ++i) {
      update(i, a[i]);
    }
  }

  void update(std::vector<long long> &b, long long idx, long long x) {
    for (++idx; idx < n; idx += idx & -idx) {
      b[idx] += x;
    }
  }

  void update(long long l, long long r, long long x) {
    update(b1, l, x);
    update(b1, r + 1, -x);
    update(b2, l, x * (l - 1));
    update(b2, r + 1, -x * r);
  }

  void update(long long idx, long long x) { update(idx, idx, x); }

  long long query(std::vector<long long> &b, long long idx) {
    long long total = 0;
    for (++idx; idx > 0; idx -= idx & -idx) {
      total += b[idx];
    }
    return total;
  }

  long long query(long long idx) {
    return query(b1, idx) * idx - query(b2, idx);
  }

  long long query(long long l, long long r) {
    return query(r + 1) - query(l - 1);
  }
};
