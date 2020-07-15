/*
ID: zhaowei10
TASK:
LANG: C++14
*/
#include "bits/stdc++.h"

using namespace std;

#ifdef LOCAL
#include "../../_library/cc/debug.h"
#define FILE "test"
#else
#define debug(...) 0
#define FILE ""
#endif

struct SegmentTree {
  int l, r;
  SegmentTree *lc, *rc;
  int sum;

  SegmentTree(vector<int>& a, int l, int r) {
    this->l = l;
    this->r = r;
    if (l == r) {
      sum = a[l];
      return;
    }
    int m = l + (r - l) / 2;
    lc = new SegmentTree(a, l, m);
    rc = new SegmentTree(a, m + 1, r);
    sum = lc->sum + rc->sum;
  }

  void update(int i, int x) {
    if (l == r) {
      sum = x;
      return;
    }
    int m = l + (r - l) / 2;
    if (i <= m) {
      lc->update(i, x);
    } else {
      rc->update(i, x);
    }
    sum = lc->sum + rc->sum;
  }

  int query(int k) {
    if (l == r) {
      return l;
    }
    if (k <= lc->sum) {
      return lc->query(k);
    }
    return rc->query(k - lc->sum);
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
  vector<int> a(n);
  for (auto& x : a)
    cin >> x;

  SegmentTree st(a, 0, a.size() - 1);
  while (m--) {
    int x, y;
    cin >> x >> y;
    if (x == 1) {
      a[y] ^= 1;
      st.update(y, a[y]);
    } else {
      cout << st.query(y + 1) << '\n';
    }
  }
}
