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
  int64_t inv = 0;
  array<int, 40> cnt{};
};

struct SegTree {
  int l, r;
  SegTree *lc, *rc;
  Value val;

  Value identity() {
    Value res;
    return res;
  }

  Value single(int x) {
    Value res;
    res.cnt[x] = 1;
    return res;
  }

  Value merge(Value a, Value b) {
    Value res;
    res.inv = a.inv + b.inv;
    int cur = 0;
    for (int i = 0; i < 40; ++i) {
      res.inv += (int64_t)cur * a.cnt[i];
      cur += b.cnt[i];
      res.cnt[i] = a.cnt[i] + b.cnt[i];
    }
    return res;
  }

  SegTree(vector<int>& a, int _l, int _r) : l(_l), r(_r) {
    if (l == r - 1) {
      val = single(a[l]);
      return;
    }

    int m = l + (r - l) / 2;
    lc = new SegTree(a, l, m);
    rc = new SegTree(a, m, r);
    val = merge(lc->val, rc->val);
  }

  void set(int idx, int x) {
    if (l == r - 1) {
      val = single(x);
      return;
    }

    int m = l + (r - l) / 2;
    if (idx < m) {
      lc->set(idx, x);
    } else {
      rc->set(idx, x);
    }
    val = merge(lc->val, rc->val);
  }

  Value count(int _l, int _r) {
    if (l >= _r || r <= _l)
      return identity();
    if (l >= _l && r <= _r)
      return val;
    auto a = lc->count(_l, _r);
    auto b = rc->count(_l, _r);
    return merge(a, b);
  }
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
  for (auto& x : a) {
    cin >> x;
    --x;
  }

  SegTree t(a, 0, n);
  while (q--) {
    int a, b, c;
    cin >> a >> b >> c;
    if (a == 1) {
      cout << t.count(b - 1, c).inv << '\n';
    } else {
      t.set(b - 1, c - 1);
    }
  }
}
