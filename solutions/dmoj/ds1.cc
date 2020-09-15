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

struct FenwickTree {
  vector<int64_t> t;
  int n;

  FenwickTree(int _n) {
    n = _n + 1;
    t.resize(n);
  }

  void add(int i, int x) {
    for (++i; i < n; i += i & -i) {
      t[i] += x;
    }
  }

  int64_t query(int l, int r) { return query(r) - (l ? query(l - 1) : 0); }

  int64_t query(int i) {
    int64_t res = 0;
    for (++i; i; i -= i & -i) {
      res += t[i];
    }
    return res;
  }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  // 2 different standard uses of a BIT:
  // 1. As an order statistic tree
  // 2. Prefix sums
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  FenwickTree sums(n), counts(100001);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    sums.add(i, a[i]);
    counts.add(a[i], 1);
  }

  while (m--) {
    char cmd;
    cin >> cmd;
    if (cmd == 'C') {
      int i, v;
      cin >> i >> v;
      --i;
      sums.add(i, v - a[i]);
      counts.add(a[i], -1);
      counts.add(v, 1);
      a[i] = v;
    } else if (cmd == 'S') {
      int l, r;
      cin >> l >> r;
      --l, --r;
      cout << sums.query(l, r) << '\n';
    } else {
      int v;
      cin >> v;
      cout << counts.query(v) << '\n';
    }
  }
}
