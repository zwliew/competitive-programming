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

  void update(int i, T val) {
    assert(i >= 0 && i < (int)size());
    for (++i; i < (int)dat.size(); i += i & -i) {
      dat[i] += val;
    }
  }

  T query(int i) const {
    assert(i >= 0 && i < (int)size());
    T res = 0;
    for (++i; i; i -= i & -i) {
      res += dat[i];
    }
    return res;
  }
};
