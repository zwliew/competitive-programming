/*
ID: zhaowei10
TASK:
LANG: C++14
*/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 0
#endif

template <typename T>
struct DisjointSet {
  std::vector<T> p, r, sz;
  size_t numSets;

  DisjointSet(size_t n) {
    p.assign(n, -1);
    r.assign(n, 0);
    sz.assign(n, 1);
    numSets = n;
  }

  T find(T x) { return p[x] < 0 ? x : p[x] = find(p[x]); }

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
    --numSets;
    return true;
  }

  size_t size(T x) { return sz[find(x)]; }

  bool sameSet(T x, T y) { return find(x) == find(y); }
};

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

#ifdef LOCAL
  freopen("test.in", "r", stdin);
  freopen("test.out", "w", stdout);
#else
#endif

  int n, e;
  cin >> n >> e;
  vector<tuple<int, int, int>> edges;
  for (int i = 0; i < e; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    --u, --v;
    edges.emplace_back(w, u, v);
  }
  sort(edges.begin(), edges.end());

  DisjointSet<int> dsu(n);
  for (int i = 0; i < edges.size(); ++i) {
    auto &[w, u, v] = edges[i];
    if (!dsu.sameSet(u, v)) {
      dsu.join(u, v);
      if (dsu.sameSet(0, n - 1)) {
        cout << w << '\n';
        return 0;
      }
    }
  }
}
