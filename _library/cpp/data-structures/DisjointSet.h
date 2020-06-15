#include <vector>

template <typename T>
struct DisjointSet {
  std::vector<T> p, r, sz;
  size_t count;

  DisjointSet(size_t n) {
    p.assign(n, -1);
    r.assign(n, 0);
    sz.assign(n, 1);
    count = n;
  }

  T find(T x) { return p[x] < 0 ? x : p[x] = ffind(p[x]); }

  bool join(T x, T y) {
    x = find(x);
    y = find(y);
    if (x == y) return false;
    if (r[x] < r[y])
      std::swap(x, y);
    else if (r[x] == r[y])
      ++r[x];
    p[y] = x;
    sz[x] += sz[y];
    --count;
    return true;
  }

  size_t size(T x) { return sz[find(x)]; }

  bool sameSet(T x, T y) { return find(x) == find(y); }
};