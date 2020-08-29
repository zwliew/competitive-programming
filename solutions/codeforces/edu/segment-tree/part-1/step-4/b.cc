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

using Mat = array<array<int, 2>, 2>;
int mod;

Mat IDENTITY;

struct SegTree {
  int l, r;
  SegTree *lc, *rc;
  Mat val;

  SegTree(vector<Mat>& a, int _l, int _r) : l(_l), r(_r) {
    if (l == r - 1) {
      val = a[l];
      return;
    }
    int m = l + (r - l) / 2;
    lc = new SegTree(a, l, m);
    rc = new SegTree(a, m, r);
    val = merge(lc->val, rc->val);
  }

  Mat merge(Mat a, Mat b) {
    Mat res{};
    for (int i = 0; i < 2; ++i) {
      for (int j = 0; j < 2; ++j) {
        for (int k = 0; k < 2; ++k) {
          res[i][j] += a[i][k] * b[k][j];
          res[i][j] %= mod;
        }
      }
    }
    return res;
  }

  Mat prod(int _l, int _r) {
    if (l >= _r || r <= _l)
      return IDENTITY;
    if (l >= _l && r <= _r)
      return val;
    return merge(lc->prod(_l, _r), rc->prod(_l, _r));
  }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 2; ++j) {
      IDENTITY[i][j] = i == j;
    }
  }

  int n, m;
  cin >> mod >> n >> m;
  vector<Mat> a(n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 2; ++j) {
      for (int k = 0; k < 2; ++k) {
        cin >> a[i][j][k];
      }
    }
  }

  SegTree t(a, 0, n);
  while (m--) {
    int l, r;
    cin >> l >> r;
    auto res = t.prod(l - 1, r);
    for (int i = 0; i < 2; ++i) {
      for (int j = 0; j < 2; ++j) {
        cout << res[i][j] << " ";
      }
      cout << "\n";
    }
    cout << "\n";
  }
}
