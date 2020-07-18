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

struct Value {
  int cnt[41];
};

struct SegmentTree {
  vector<Value> vals;
  int sz;

  SegmentTree(vector<int>& a) {
    sz = a.size();
    vals = vector<Value>(sz * 4);
    build(a, 1, 0, sz - 1);
  }

  void build(vector<int>& a, int ti, int tl, int tr) {
    if (tl == tr) {
      vals[ti].cnt[a[tl]] = 1;
      return;
    }
    int tm = tl + (tr - tl) / 2;
    build(a, ti * 2, tl, tm);
    build(a, ti * 2 + 1, tm + 1, tr);
    vals[ti] = merge(vals[ti * 2], vals[ti * 2 + 1]);
  }

  Value merge(Value a, Value b) {
    Value res;
    for (int i = 1; i <= 40; ++i) {
      res.cnt[i] = a.cnt[i] + b.cnt[i];
    }
    return res;
  }

  void assign(int i, int x) { assign(i, x, 1, 0, sz - 1); }

  void assign(int i, int x, int ti, int tl, int tr) {
    if (tl == tr) {
      int found = -1;
      for (int i = 1; i <= 40; ++i) {
        if (vals[ti].cnt[i]) {
          found = i;
          break;
        }
      }
      vals[ti].cnt[found] = 0;
      vals[ti].cnt[x] = 1;
      return;
    }
    int tm = tl + (tr - tl) / 2;
    if (i <= tm) {
      assign(i, x, ti * 2, tl, tm);
    } else {
      assign(i, x, ti * 2 + 1, tm + 1, tr);
    }
    vals[ti] = merge(vals[ti * 2], vals[ti * 2 + 1]);
  }

  Value query(int l, int r) { return query(l, r, 1, 0, sz - 1); }

  Value query(int l, int r, int ti, int tl, int tr) {
    if (tl > r || tr < l)
      return {};
    if (l <= tl && tr <= r) {
      return vals[ti];
    }
    int tm = tl + (tr - tl) / 2;
    return merge(query(l, r, ti * 2, tl, tm),
                 query(l, r, ti * 2 + 1, tm + 1, tr));
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
  for (auto& x : a)
    cin >> x;
  SegmentTree t(a);
  while (q--) {
    int op, x, y;
    cin >> op >> x >> y;
    --x;
    if (op == 1) {
      --y;
      Value res = t.query(x, y);
      int cnt = 0;
      for (int i = 1; i <= 40; ++i) {
        if (res.cnt[i]) {
          ++cnt;
        }
      }
      cout << cnt << '\n';
    } else {
      t.assign(x, y);
    }
  }
}
