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
//#include "bits/stdc++.h"

using namespace std;

#ifdef LOCAL
#include "../../_library/cc/debug.h"
#define FILE "test"
#else
#define debug(...) 0
#define FILE ""
#endif

struct SegmentTree {
  vector<int> mins;
  int n;

  SegmentTree(int _n) : n(_n) { mins.assign(n * 4, INT_MAX); }

  void set(int i, int h) { set(i, h, 0, 0, n); }

  void set(int i, int h, int ti, int tl, int tr) {
    if (tl == tr - 1) {
      mins[ti] = h;
      return;
    }
    int tm = tl + (tr - tl) / 2;
    if (i < tm) {
      set(i, h, ti * 2 + 1, tl, tm);
    } else {
      set(i, h, ti * 2 + 2, tm, tr);
    }
    mins[ti] = min(mins[ti * 2 + 1], mins[ti * 2 + 2]);
  }

  int remove(int l, int r, int p) { return remove(l, r, p, 0, 0, n); }

  int remove(int l, int r, int p, int ti, int tl, int tr) {
    if (tl >= r || tr <= l || mins[ti] > p)
      return 0;
    if (tl == tr - 1) {
      mins[ti] = INT_MAX;
      return 1;
    }
    int tm = tl + (tr - tl) / 2;
    int ans = remove(l, r, p, ti * 2 + 1, tl, tm) +
              remove(l, r, p, ti * 2 + 2, tm, tr);
    mins[ti] = min(mins[ti * 2 + 1], mins[ti * 2 + 2]);
    return ans;
  }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int n, m;
  cin >> n >> m;
  SegmentTree t(n);
  while (m--) {
    int cmd;
    cin >> cmd;
    if (cmd == 1) {
      int i, h;
      cin >> i >> h;
      t.set(i, h);
    } else {
      int l, r, p;
      cin >> l >> r >> p;
      cout << t.remove(l, r, p) << "\n";
    }
  }
}
