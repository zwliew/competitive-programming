/*
ID: zhaowei10
TASK:
LANG: C++14
*/
#include "bits/extc++.h"

using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;

#ifdef LOCAL
#include "../../_library/cpp/debug.h"
#define FILE "test"
#else
#define debug(...) 0
#define FILE ""
#endif

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

  // Joins x to y, disregarding rank
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
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (auto &x : a) cin >> x;

  vector<vector<pair<int, int>>> queries(n);
  for (int i = 0; i < q; ++i) {
    int l, r;
    cin >> l >> r;
    --r;
    queries[r].emplace_back(l, i);
  }

  vector<int> ans(q);
  DisjointSet<int> dsu(n);
  stack<int> st;
  for (int i = 0; i < n; ++i) {
    while (st.size() && a[st.top()] > a[i]) {
      dsu.joinTo(st.top(), i);
      st.pop();
    }
    st.push(i);
    for (auto &[l, idx] : queries[i]) {
      ans[idx] = dsu.find(l);
    }
  }

  for (auto x : ans) {
    cout << a[x] << '\n';
  }
}
