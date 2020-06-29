/*
ID: zhaowei10
TASK:
LANG: C++14
*/
#include "bits/stdc++.h"

using namespace std;

#ifdef LOCAL
#include "../../_library/cpp/debug.h"
#define FILE "test"
#else
#define debug(...) 0
#define FILE ""
#endif

struct Node {
  Node *left;
  Node *right;
  int64_t tmax, pmax, smax;
  int64_t sum;
  int lo, hi;

  Node(int l, int r, vector<int> &arr) : lo(l), hi(r) {
    if (lo == hi) {
      sum = smax = tmax = pmax = arr[l];
      return;
    }
    int mid = lo + (hi - lo) / 2;
    left = new Node(lo, mid, arr);
    right = new Node(mid + 1, hi, arr);
    compute();
  }

  void compute() {
    if (lo == hi)
      return;
    tmax = max({left->tmax, right->tmax, left->smax + right->pmax});
    sum = left->sum + right->sum;
    pmax = max(left->pmax, left->sum + right->pmax);
    smax = max(right->smax, right->sum + left->smax);
  }

  void update(int idx, int val) {
    if (lo == hi) {
      sum = tmax = pmax = smax = val;
      return;
    }

    if (idx <= left->hi) {
      left->update(idx, val);
    } else {
      right->update(idx, val);
    }
    compute();
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
  for (int &x : a)
    cin >> x;
  auto root = new Node(0, n - 1, a);
  while (m--) {
    int k, x;
    cin >> k >> x;
    root->update(k - 1, x);
    cout << max<int64_t>(0, root->tmax) << '\n';
  }
}
