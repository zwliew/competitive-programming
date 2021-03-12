#include "bits/stdc++.h"
using namespace std;
#define debug(...) 0
#ifdef LOCAL
#include "../../_library/cc/debug.h"
#endif
// #define FILE

inline void solve() {
  int A, B;
  cin >> A >> B;

  int ans = INT_MAX;
  for (int i = 0; i <= 30; ++i) {
    if (B + i == 1) continue;
    int cur = A;
    int cnt = i;
    while (cur) {
      cur /= B + i;
      cnt++;
    }
    ans = min(ans, cnt);
  }

  cout << ans << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
#if defined(FILE) && !defined(LOCAL)
  freopen(FILE ".in", "r", stdin), freopen(FILE ".out", "w", stdout);
#endif

  int T;
  cin >> T;
  while (T--) {
    solve();
  }
}
