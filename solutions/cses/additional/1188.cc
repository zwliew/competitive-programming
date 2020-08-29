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
  int mx, len;
  array<array<int, 2>, 2> csc;
};

struct Node {
  int l, r;
  Node *lc, *rc;
  Value val;

  Node(string& s, int _l, int _r) : l(_l), r(_r) {
    if (l == r - 1) {
      Value res;
      val.mx = 1;
      val.len = 1;
      for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
          val.csc[i][j] = s[l] - '0' == j;
        }
      }
      return;
    }
    int m = l + (r - l) / 2;
    lc = new Node(s, l, m);
    rc = new Node(s, m, r);
    val = merge(lc->val, rc->val);
  }

  void invert(int i) {
    if (l == r - 1) {
      for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
          val.csc[i][j] = !val.csc[i][j];
        }
      }
      return;
    }
    int m = l + (r - l) / 2;
    if (i < m) {
      lc->invert(i);
    } else {
      rc->invert(i);
    }
    val = merge(lc->val, rc->val);
  }

  Value merge(Value a, Value b) {
    Value res;
    res.len = a.len + b.len;
    for (int i = 0; i < 2; ++i) {
      res.csc[0][i] = a.csc[0][i] + (a.csc[0][i] == a.len ? b.csc[0][i] : 0);
      res.csc[1][i] = b.csc[1][i] + (b.csc[1][i] == b.len ? a.csc[1][i] : 0);
    }
    res.mx =
        max({a.mx, b.mx, a.csc[1][0] + b.csc[0][0], a.csc[1][1] + b.csc[0][1]});
    return res;
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
  Node t(s, 0, s.size());

  int m;
  cin >> m;
  while (m--) {
    int x;
    cin >> x;
    --x;
    t.invert(x);
    cout << t.val.mx << ' ';
  }
}
