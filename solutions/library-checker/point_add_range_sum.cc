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
struct PURQFenwickTree {
  std::vector<T> t;

  PURQFenwickTree(size_t n) : t(n + 1) {}

  void update(int idx, T val) {
    for (++idx; idx < t.size(); idx += idx & -idx) {
      t[idx] += val;
    }
  }

  T query(int idx) {
    T res = 0;
    for (++idx; idx; idx -= idx & -idx) {
      res += t[idx];
    }
    return res;
  }
};

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

#ifdef LOCAL
  freopen("test.in", "r", stdin);
  freopen("test.out", "w", stdout);
#else
#endif

  int n, q;
  cin >> n >> q;
  PURQFenwickTree<long long> t(n);
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    t.update(i, x);
  }

  while (q--) {
    int a, b, c;
    cin >> a >> b >> c;
    if (a) {
      cout << t.query(c - 1) - t.query(b - 1) << '\n';
    } else {
      t.update(b, c);
    }
  }
}
