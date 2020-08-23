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
#define FILE "bcount"
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int N, Q;
  cin >> N >> Q;
  array<vector<int>, 3> breeds;
  for (int i = 0; i < 3; ++i) {
    breeds[i].emplace_back(0);
  }

  for (int i = 0; i < N; ++i) {
    int x;
    cin >> x;
    --x;
    for (int j = 0; j < 3; ++j) {
      breeds[j].emplace_back(x == j);
    }
  }

  for (int i = 0; i < 3; ++i) {
    partial_sum(breeds[i].begin(), breeds[i].end(), breeds[i].begin());
  }

  while (Q--) {
    int l, r;
    cin >> l >> r;
    for (int i = 0; i < 3; ++i) {
      cout << breeds[i][r] - breeds[i][l - 1];
      if (i < 2) {
        cout << ' ';
      }
    }
    cout << '\n';
  }
}
