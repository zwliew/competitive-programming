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
#define FILE "paintbarn"
#endif

struct SegmentTree {
  int l, r;
  SegmentTree *lChild, *rChild;
  int64_t val;
  bool mult;

  SegmentTree(vector<int64_t>& a, int ll, int lr, bool lMult)
      : l(ll), r(lr), mult(lMult) {
    if (ll == lr) {
      val = a[ll] * (ll % 2 ? 1 : -1) * (mult ? l : 1);
      return;
    }
    int m = ll + (lr - ll) / 2;
    lChild = new SegmentTree(a, l, m, mult);
    rChild = new SegmentTree(a, m + 1, r, mult);
    val = lChild->val + rChild->val;
  }

  void update(int idx, int lval) {
    if (l == r) {
      val = lval * (l % 2 ? 1 : -1) * (mult ? l : 1);
      return;
    }
    int m = l + (r - l) / 2;
    if (idx <= m) {
      lChild->update(idx, lval);
    } else {
      rChild->update(idx, lval);
    }
    val = lChild->val + rChild->val;
  }

  int64_t sum(int ll, int lr) {
    if (l > lr || r < ll)
      return 0;
    if (l >= ll && r <= lr)
      return val;
    return lChild->sum(ll, lr) + rChild->sum(ll, lr);
  }
};

// void computePrefSums(vector<int64_t>& a,
//                      vector<int64_t>& pref,
//                      vector<int64_t>& multPref,
//                      int l) {
//   int sign = l % 2 ? 1 : -1;
//   for (int i = l; i < a.size(); ++i) {
//     multPref[i] = a[i] * i * sign + multPref[i - 1];
//     pref[i] = a[i] * sign + pref[i - 1];
//     sign *= -1;
//   }
// }

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int t;
  cin >> t;
  for (int tt = 1; tt <= t; ++tt) {
    int n, q;
    cin >> n >> q;
    vector<int64_t> a(n + 1);
    for (int i = 1; i <= n; ++i) {
      cin >> a[i];
    }

    // Solution using prefix sums instead of segment trees.
    // Ideal if there are very few update queries.
    // vector<int64_t> pref(n + 1), multPref(n + 1);
    // computePrefSums(a, pref, multPref, 1);

    SegmentTree st(a, 1, n, false), multSt(a, 1, n, true);
    int64_t sum = 0;
    while (q--) {
      char op;
      int l, r;
      cin >> op >> l >> r;
      if (op == 'U') {
        st.update(l, r);
        multSt.update(l, r);
        // a[l] = r;
        // computePrefSums(a, pref, multPref, l);
      } else {
        sum += (l % 2 ? 1 : -1) * (multSt.sum(l, r) - (l - 1) * st.sum(l, r));
        // sum += (l % 2 ? 1 : -1) * (multPref[r] - multPref[l - 1] -
        //                             (l - 1) * (pref[r] - pref[l - 1]));
      }
    }

    cout << "Case #" << tt << ": " << sum << '\n';
  }
}
