#include <numeric>
#include <vector>

struct DisjointSet {
  std::vector<long long> parent;
  std::vector<long long> rank;
  std::vector<long long> size;
  long long numSets;

  DisjointSet(long long n) {
    numSets = n;
    parent.assign(n, 0);
    rank.assign(n, 1);
    size.assign(n, 1);
    iota(parent.begin(), parent.end(), 0);
  }

  long long findSet(long long a) {
    return parent[a] == a ? a : (parent[a] = findSet(parent[a]));
  }

  void unionSet(long long a, long long b) {
    long long as = findSet(a);
    long long bs = findSet(b);
    if (as == bs) return;
    if (rank[as] < rank[bs]) std::swap(a, b);
    if (rank[as] == rank[bs]) ++rank[as];
    parent[bs] = as;
    size[as] += size[bs];
    --numSets;
  }

  bool sameSet(long long a, long long b) { return findSet(a) == findSet(b); }

  long long sizeOfSet(long long a) { return size[findSet(a)]; }

  long long numOfSets() { return numSets; }
};