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

  int N;
  cin >> N;
  vector<array<int, 4>> A(N);
  for (auto& a : A) {
    cin >> a[0] >> a[1] >> a[2] >> a[3];
  }

  int ans = N;
  for (int i = 0; i < N; ++i) {
    bool engulfed = false;
    for (int j = 0; j < N && !engulfed; ++j) {
      if (i == j)
        continue;
      engulfed = A[i][0] >= A[j][0] && A[i][2] <= A[j][2] &&
                 A[i][1] >= A[j][1] && A[i][3] <= A[j][3];
    }

    if (engulfed) {
      --ans;
    }
  }
  cout << ans;
}
