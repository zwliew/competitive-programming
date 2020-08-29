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
#define FILE "balancing"
#endif

struct Value {
  int mx;
  int open;
  int closed;
};

struct SegmentTree {
  int l, r;
  SegmentTree *lc, *rc;
  Value val;

  SegmentTree(string& s, int _l, int _r) : l(_l), r(_r) {
    if (l == r - 1) {
      val.mx = 0;
      val.open = s[l] == '(';
      val.closed = s[l] == ')';
      return;
    }
    int m = l + (r - l) / 2;
    lc = new SegmentTree(s, l, m);
    rc = new SegmentTree(s, m, r);
    val = compute(lc->val, rc->val);
  }

  Value compute(Value a, Value b) {
    Value res;
    int paired = min(a.open, b.closed);
    res.mx = a.mx + b.mx + paired;
    res.open = a.open + b.open - paired;
    res.closed = a.closed + b.closed - paired;
    return res;
  }

  Value query(int _l, int _r) {
    if (l >= _r || r <= _l)
      return {0, 0, 0};
    if (l >= _l && r <= _r)
      return val;
    return compute(lc->query(_l, _r), rc->query(_l, _r));
  }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  string s;
  cin >> s;
  SegmentTree t(s, 0, (int)s.size());
  int m;
  cin >> m;
  while (m--) {
    int l, r;
    cin >> l >> r;
    --l;
    cout << t.query(l, r).mx * 2 << '\n';
  }
}
