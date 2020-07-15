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
  int mx;

  SegmentTree(vector<int>& a, int l, int r) {
    this->l = l;
    this->r = r;
    if (l == r) {
      mx = a[l];
      return;
    }
    int m = l + (r - l) / 2;
    lc = new SegmentTree(a, l, m);
    rc = new SegmentTree(a, m + 1, r);
    mx = max(lc->mx, rc->mx);
  }

  void update(int i, int x) {
    if (l == r) {
      mx = x;
      return;
    }
    int m = l + (r - l) / 2;
    if (i <= m) {
      lc->update(i, x);
    } else {
      rc->update(i, x);
    }
    mx = max(lc->mx, rc->mx);
  }

  int query(int x) {
    if (l == r) {
      return l;
    }
    if (lc->mx >= x) {
      return lc->query(x);
    }
    return rc->query(x);
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
    int x, y, z;
    cin >> x >> y;
    if (x == 1) {
      cin >> z;
      st.update(y, z);
    } else if (st.mx < y) {
      cout << "-1\n";
    } else {
      cout << st.query(y) << '\n';
    }
  }
}
