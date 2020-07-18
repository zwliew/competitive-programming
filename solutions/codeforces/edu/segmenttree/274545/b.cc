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
  int n;
  vector<int> sum;

  SegmentTree(int sz) : n(sz) {
    sum.resize(sz * 4);
    build(0, 0, n - 1);
  }

  void build(int ti, int tl, int tr) {
    if (tl == tr) {
      sum[ti] = 1;
      return;
    }
    int tm = tl + (tr - tl) / 2;
    build(ti * 2 + 1, tl, tm);
    build(ti * 2 + 2, tm + 1, tr);
    sum[ti] = sum[ti * 2 + 1] + sum[ti * 2 + 2];
  }

  void update(int i, int x) { update(i, x, 0, 0, n - 1); }

  void update(int i, int x, int ti, int tl, int tr) {
    if (tl == tr) {
      sum[ti] = x;
      return;
    }
    int tm = tl + (tr - tl) / 2;
    if (i <= tm) {
      update(i, x, ti * 2 + 1, tl, tm);
    } else {
      update(i, x, ti * 2 + 2, tm + 1, tr);
    }
    sum[ti] = sum[ti * 2 + 1] + sum[ti * 2 + 2];
  }

  int kthLargest(int k) { return kthLargest(k, 0, 0, n - 1); }

  int kthLargest(int k, int ti, int tl, int tr) {
    if (sum[ti] < k) {
      return -1;
    }
    if (tl == tr) {
      return tl;
    }
    int tm = tl + (tr - tl) / 2;
    int ans = kthLargest(k, ti * 2 + 2, tm + 1, tr);
    if (ans == -1) {
      ans = kthLargest(k - sum[ti * 2 + 2], ti * 2 + 1, tl, tm);
    }
    return ans;
  }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int n;
  cin >> n;
  vector<int> a(n);
  for (auto& x : a)
    cin >> x;
  reverse(a.begin(), a.end());

  SegmentTree st(n);
  stack<int> ans;
  for (int x : a) {
    int cur = st.kthLargest(x + 1);
    ans.emplace(cur + 1);
    st.update(cur, 0);
  }
  while (ans.size()) {
    cout << ans.top() << ' ';
    ans.pop();
  }
}
