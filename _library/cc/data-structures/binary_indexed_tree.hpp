#include <vector>

template <typename T>
class binary_indexed_tree {
 private:
  std::vector<T> dat;

 public:
  binary_indexed_tree(size_t N) : dat(N + 1) {}
  binary_indexed_tree(size_t N, T t) : dat(N + 1) {
    for (int i = 0; i < (int)N; ++i) {
      update(i, t);
    }
  }

  size_t size() const { return dat.size() - 1; }
  const std::vector<T> data() const { return dat; }

  // Adds val to the element at index i
  void add(int i, T val) {
    assert(i >= 0 && i < (int)size());
    for (++i; i < (int)dat.size(); i += i & -i) {
      dat[i] += val;
    }
  }

  // Returns the sum of elements in range [0, r)
  T query(int r) const {
    assert(r >= 0 && r <= (int)size());
    T res = 0;
    for (; r; r -= r & -r) {
      res += dat[r];
    }
    return res;
  }

  // Returns the sum of elements in range [l, r)
  T sum(int l, int r) const {
    return query(r) - query(l);
  }
};
