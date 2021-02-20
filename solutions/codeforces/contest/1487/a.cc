#include "bits/stdc++.h"
using namespace std;
#define debug(...) 0
#ifdef LOCAL
#include "../../_library/cc/debug.h"
#endif
// #define FILE

inline void solve() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (auto &x : A) cin >> x;
  cout << N - count(A.begin(), A.end(), *min_element(A.begin(), A.end())) << "\n";
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
