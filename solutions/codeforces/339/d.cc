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
  int lo, hi;
  SegmentTree *left, *right;
  bool odd;
  int val;

  SegmentTree(vector<int> &a, int lo, int hi) : lo(lo), hi(hi) {
    if (lo == hi) {
      val = a[lo];
      odd = true;
      return;
    }

    int mid = lo + (hi - lo) / 2;
    left = new SegmentTree(a, lo, mid);
    right = new SegmentTree(a, mid + 1, hi);

    odd = !left->odd;
    compute();
  }

  void assign(int idx, int val) {
    if (lo == hi) {
      this->val = val;
      return;
    }

    if (idx <= left->hi) {
      left->assign(idx, val);
    } else {
      right->assign(idx, val);
    }
    compute();
  }

  void compute() {
    val = odd ? left->val ^ right->val : left->val | right->val;
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
  vector<int> a(1 << n);
  for (auto &x : a)
    cin >> x;

  SegmentTree *st = new SegmentTree(a, 0, (1 << n) - 1);
  while (m--) {
    int p, b;
    cin >> p >> b;
    st->assign(p - 1, b);
    cout << st->val << '\n';
  }
}
