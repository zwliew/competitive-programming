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
    string A, B;
    cin >> A >> B;

    int lcmLen = lcm(A.size(), B.size());
    string ans;
    for (int i = 0; i < lcmLen; ++i) {
      if (A[i % A.size()] != B[i % B.size()]) {
        break;
      }
      ans += A[i % A.size()];
    }

    if (ans.size() == lcmLen) {
      cout << ans;
    } else {
      cout << -1;
    }
    cout << "\n";
  }
}
