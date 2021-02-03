#include <bits/stdc++.h>
using namespace std;
#define debug(...) 0
#ifdef LOCAL
#include "../../_library/cc/debug.h"
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
#if defined(FILE) && !defined(LOCAL)
  freopen(FILE ".in", "r", stdin), freopen(FILE ".out", "w", stdout);
#endif

  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    vector<int> A(N);
    for (auto& x : A)
      cin >> x;

    int ans = 0;
    for (int i = 0; i < N;) {
      int j = i;
      while (j < N && A[j] == A[i]) {
        ++j;
      }
      ans = max(ans, j - i);
      i = j;
    }
    cout << ans << "\n";
  }
}
