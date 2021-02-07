#include <bits/stdc++.h>
using namespace std;
#define debug(...) 0
#ifdef LOCAL
#include "../../_library/cc/debug.h"
#endif
// #define FILE

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
#if defined(FILE) && !defined(LOCAL)
  freopen(FILE ".in", "r", stdin), freopen(FILE ".out", "w", stdout);
#endif

  int T;
  cin >> T;
  while (T--) {
    int N, D;
    cin >> N >> D;
    vector<int> A(N);
    for (auto &x : A) cin >> x;
    sort(A.begin(), A.end());
    cout << (min(A.back(), A[0] + A[1]) <= D ? "yes\n" : "no\n");
  }
}
