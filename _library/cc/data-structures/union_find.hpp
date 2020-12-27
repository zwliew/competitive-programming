#include <cassert>
#include <numeric>
#include <vector>

/**
 * Union-find (AKA disjoint-set)
 *
 * Stores a collection of sets and supports merging 2 sets and finding the
 * representative of each set.
 *
 * Notable applications:
 * Kruskal's algorithm for finding the MST of a graph
 * Tarjan's offline LCA algorithm for computing the LCA of 2 vertices in a tree
 * Arpa's offline RMQ trick for computing the min value in a range
 */
class union_find {
 private:
  std::vector<int> rep, cnt;
  int sz;

 public:
  union_find(int N) : rep(N), sz(N) { std::iota(rep.begin(), rep.end(), 0); }
  union_find(int N, bool count) : union_find(N) {
    if (count) {
      cnt.assign(N, 1);
    }
  }

  size_t size() const { return sz; }
  const std::vector<int> data() const { return rep; }
  size_t count(int u) {
    assert(!cnt.empty());
    return cnt[find(u)];
  }

  int find(int u) {
    assert(u >= 0 && u < (int)rep.size());
    return rep[u] == u ? u : rep[u] = find(rep[u]);
  }

  // Unites u *to* v.
  bool unite(int u, int v) {
    assert(u >= 0 && u < (int)rep.size());
    assert(v >= 0 && v < (int)rep.size());
    u = find(u);
    v = find(v);
    if (u == v)
      return false;
    rep[u] = v;
    if (!cnt.empty()) {
      cnt[v] += cnt[u];
    }
    --sz;
    return true;
  }

  bool same(int u, int v) { return find(u) == find(v); }
};

class union_find_rank : union_find {
 private:
  std::vector<int> rank;

 public:
  union_find_rank(int N) : union_find(N), rank(N) {}

  // Respects rank.
  bool unite(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v)
      return false;
    if (rank[u] > rank[v]) {
      std::swap(u, v);
    } else if (rank[u] == rank[v]) {
      ++rank[v];
    }
    return union_find::unite(u, v);
  }
};
