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
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#ifdef LOCAL
#include "../../_library/cc/debug.h"
#define FILE "test"
#else
#define debug(...) 0
#define FILE ""
#endif

#define FALSE 0
#define MAYBE 1
#define TRUE 2

struct SegTree {
  vector<int> t;
  int n;
  SegTree(vector<pair<int, int>>& a) {
    n = a.size();
    t.resize(4 * n);
    build(a, 0, 0, n);
  }

  void build(vector<pair<int, int>>& a, int ti, int tl, int tr) {
    if (tl == tr - 1) {
      t[ti] = a[tl].second;
      return;
    }
    int tm = tl + (tr - tl) / 2;
    build(a, ti * 2 + 1, tl, tm);
    build(a, ti * 2 + 2, tm, tr);
    t[ti] = max(t[ti * 2 + 1], t[ti * 2 + 2]);
  }

  int mx(int l, int r) { return mx(l, r, 0, 0, n); }

  int mx(int l, int r, int ti, int tl, int tr) {
    if (tl >= r || tr <= l)
      return INT_MIN;
    if (tl >= l && tr <= r)
      return t[ti];
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

  int n, m;
  while (cin >> n && n) {
    vector<pair<int, int>> years(n);
    for (auto& [y, r] : years) {
      cin >> y >> r;
    }
    sort(years.begin(), years.end());

    unordered_map<int, int> comp;
    for (int i = 0; i < n; ++i) {
      comp[years[i].first] = i;
    }

    SegTree segTree(years);

    cin >> m;
    while (m--) {
      int l, r;
      cin >> l >> r;

      int knownYears =
          lower_bound(years.begin(), years.end(), make_pair(r + 1, 0)) -
          lower_bound(years.begin(), years.end(), make_pair(l, 0));
      int res = knownYears < r - l + 1 ? MAYBE : TRUE;
      int lb = lower_bound(years.begin(), years.end(), make_pair(l + 1, 0)) -
               years.begin();
      int ub = lower_bound(years.begin(), years.end(), make_pair(r, 0)) -
               years.begin();
      int btwnMax = segTree.mx(lb, ub);
      int reqMin = INT_MIN;
      if (comp.count(r) && btwnMax >= years[comp[r]].second) {
        res = FALSE;
      } else if (!comp.count(r)) {
        reqMin = btwnMax;
      }

      if (comp.count(l) && comp.count(r) &&
          years[comp[r]].second > years[comp[l]].second) {
        res = FALSE;
      } else if (comp.count(l) && years[comp[l]].second < reqMin) {
        res = FALSE;
      }

      if (res == FALSE) {
        cout << "false";
      } else if (res == MAYBE) {
        cout << "maybe";
      } else {
        cout << "true";
      }
      cout << "\n";
    }
    cout << "\n";
  }
}
