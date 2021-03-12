#include "bits/stdc++.h"
using namespace std;
#define debug(...) 0
#ifdef LOCAL
#include "../../_library/cc/debug.h"
#endif
// #define FILE

void solve() {
  int64_t P, A, B, C;
  cin >> P >> A >> B >> C;
  cout << min({(P + A - 1) / A * A, (P + B - 1) / B * B, (P + C - 1) / C * C}) -
              P
       << '\n';
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
