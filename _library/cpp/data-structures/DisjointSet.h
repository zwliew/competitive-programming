#include <vector>

// For combining 2 sets and determining if 2 elements are in the same set.
// Time complexity: O(1) on average.
//
// Notable applications:
// Kruskal's algorithm for computing MST of a graph
// Tarjan's offline LCA algorithm for computing LCA of 2 vertices
// Arpa's trick for computing offline RMQ
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

  T find(T x) { return p[x] < 0 ? x : p[x] = find(p[x]); }

  // Joins x and y, considering rank.
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

  // Joins x to y, disregarding rank.
  // Note: the parent of x becomes the parent of y.
  bool joinTo(T x, T y) {
    x = find(x);
    y = find(y);
    if (x == y) return false;
    if (r[x] == r[y]) ++r[y];
    p[x] = y;
    sz[y] += sz[x];
    --count;
    return true;
  }

  size_t size(T x) { return sz[find(x)]; }

  bool sameSet(T x, T y) { return find(x) == find(y); }
};