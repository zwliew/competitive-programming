#include <algorithm>
#include <array>
#include <bitset>
#include <chrono>
#include <climits>
#include <cmath>
#include <cstring>
#include <deque>
#include <ext/pb_ds/assoc_container.hpp>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
// #include "bits/stdc++.h"

using namespace std;

#ifdef LOCAL
#include "../../_library/cc/debug.h"
#define FILE "test"
#else
#define debug(...) 0
#define FILE "cowjog"
#endif

struct SegmentTree {
  vector<int> vals, lazy;
  int n;

  SegmentTree(vector<int>& a) {
    n = a.size();
    vals.resize(n * 4);
    lazy.resize(n * 4);
    build(a, 0, 0, n);
  }

  void build(vector<int>& a, int ti, int tl, int tr) {
    if (tl == tr - 1) {
      vals[ti] = a[tl];
      lazy[ti] = 0;
      return;
    }
    int tm = tl + (tr - tl) / 2;
    build(a, ti * 2 + 1, tl, tm);
    build(a, ti * 2 + 2, tm, tr);
    vals[ti] = max(vals[ti * 2 + 1], vals[ti * 2 + 2]);
  }

  void add(int l, int r, int x) { add(l, r, x, 0, 0, n); }

  void add(int l, int r, int x, int ti, int tl, int tr) {
    if (l >= tr || r <= tl)
      return;
    if (l <= tl && tr <= r) {
      update(x, ti);
      return;
    }
    push(ti);
    int tm = tl + (tr - tl) / 2;
    add(l, r, x, ti * 2 + 1, tl, tm);
    add(l, r, x, ti * 2 + 2, tm, tr);
    vals[ti] = max(vals[ti * 2 + 1], vals[ti * 2 + 2]);
  }

  void update(int x, int ti) {
    vals[ti] += x;
    lazy[ti] += x;
  }

  void push(int ti) {
    update(lazy[ti], ti * 2 + 1);
    update(lazy[ti], ti * 2 + 2);
    lazy[ti] = 0;
  }

  int mx(int l, int r) { return mx(l, r, 0, 0, n); }

  int mx(int l, int r, int ti, int tl, int tr) {
    if (l >= tr || r <= tl)
      return INT_MIN;
    if (l <= tl && tr <= r)
      return vals[ti];
    push(ti);
    int tm = tl + (tr - tl) / 2;
    return max(mx(l, r, ti * 2 + 1, tl, tm), mx(l, r, ti * 2 + 2, tm, tr));
  }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  // Straightforward range max queries
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto& x : a)
    cin >> x;

  SegmentTree t(a);
  int m;
  cin >> m;
  while (m--) {
    int cmd;
    cin >> cmd;
    if (cmd) {
      int l, r, c;
      cin >> l >> r >> c;
      t.add(l, r + 1, c);
    } else {
      int l, r;
      cin >> l >> r;
      cout << t.mx(l, r + 1) << "\n";
    }
  }
}
