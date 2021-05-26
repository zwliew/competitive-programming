/**
 * Problems for testing:
 * CSES Subtree Queries -- https://cses.fi/problemset/task/1137/
 */
#include <vector>

template <typename T> class binary_indexed_tree {
private:
  std::vector<T> dat;

  const T NEUTRAL = 0;
  T merge(T a, T b) const { return a + b; }

public:
  binary_indexed_tree(size_t N) : dat(N + 1, NEUTRAL) {}
  binary_indexed_tree(size_t N, T t) : dat(N + 1, NEUTRAL) {
    for (int i = 0; i < (int)N; ++i) {
      update(i, t);
    }
  }

  size_t size() const { return dat.size() - 1; }
  const std::vector<T> data() const { return dat; }

  // Updates the element at index i with val
  void update(int i, T val) {
    assert(i >= 0 && i < (int)size());
    for (++i; i < (int)dat.size(); i += i & -i) {
      dat[i] = merge(dat[i], val);
    }
  }

  // Returns the range of elements in range [0, r)
  T query(int r) const {
    assert(r >= 0 && r <= (int)size());
    T res = NEUTRAL;
    for (; r; r -= r & -r) {
      res = merge(res, dat[r]);
    }
    return res;
  }

  // Returns the range of elements in range [l, r)
  T query(int l, int r) const { return query(r) - query(l); }
};
