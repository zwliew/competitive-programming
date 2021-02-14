#include "bits/stdc++.h"
using namespace std;
#define debug(...) 0
#ifdef LOCAL
#include "../../_library/cc/debug.h"
#endif
// #define FILE

inline void solve() {
  int N, Q, K;
  cin >> N >> Q >> K;
  vector<int> A(N);
  for (auto &x : A) cin >> x;

  vector<int> avail(N);
  for (int i = 0; i < N; ++i) {
    int mn = i ? A[i - 1] + 1 : 1;
    int mx = i < N - 1 ? A[i + 1] - 1 : K;
    avail[i] = mx - mn;
  }
  partial_sum(avail.begin(), avail.end(), avail.begin());

  for (int i = 0; i < Q; ++i) {
    int L, R;
    cin >> L >> R;
    --L, --R;
    int ans = avail[R] - (L ? avail[L - 1] : 0);
    if (L) {
      ans += A[L - 1];
    }
    if (R < N - 1) {
      ans += K - A[R + 1] + 1;
    }
    cout << ans << "\n";
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
#if defined(FILE) && !defined(LOCAL)
  freopen(FILE ".in", "r", stdin), freopen(FILE ".out", "w", stdout);
#endif

    solve();
}
