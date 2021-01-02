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

  int N, K, R;
  cin >> N >> K >> R;
  vector<int> S(N);
  for (auto& x : S)
    cin >> x;
  unordered_map<int, int> reqs;
  for (int i = 0; i < R; ++i) {
    int B, Q;
    cin >> B >> Q;
    reqs[B] = Q;
  }

  int ans = N + 1;
  int satisfied = 0;
  unordered_map<int, int> cnt;
  int l = 0;
  for (int i = 0; i < N; ++i) {
    if (reqs.count(S[i]) && cnt[S[i]] == reqs[S[i]] - 1) {
      ++satisfied;
    }
    cnt[S[i]]++;

    while (satisfied == R && (!reqs.count(S[l]) || reqs[S[l]] < cnt[S[l]])) {
      --cnt[S[l]];
      ++l;
    }

    if (satisfied == R) {
      ans = min(ans, i - l + 1);
    }
  }

  if (ans == N + 1) {
    cout << "impossible";
  } else {
    cout << ans;
  }
}
