#include <bits/stdc++.h>
using namespace std;
#define debug(...) 0
#ifdef LOCAL
#include "../../_library/cc/debug.h"
#endif
// #define FILE "milkvisits"

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
#if defined(FILE) && !defined(LOCAL)
  freopen(FILE ".in", "r", stdin), freopen(FILE ".out", "w", stdout);
#endif

  int N, K;
  cin >> N >> K;
  vector<int> A(N);

  int64_t ans = 0;
  int l = 0;
  unordered_map<int, int> cnt;
  for (int r = 0; r < N; ++r) {
    cin >> A[r];
    ++cnt[A[r]];
    while (cnt.size() > K) {
      --cnt[A[l]];
      if (!cnt[A[l]]) {
        cnt.erase(A[l]);
      }
      ++l;
    }
    ans += r - l + 1;
  }
  cout << ans;
}
