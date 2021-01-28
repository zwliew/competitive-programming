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
    int A, B, K;
    cin >> A >> B >> K;
    vector<int> boyCnt(A + 1), girlCnt(B + 1);
    vector<int> boys(K), girls(K);
    for (auto& x : boys)
      cin >> x;
    for (auto& x : girls)
      cin >> x;
    int64_t ans = 0;
    for (int i = 0; i < K; ++i) {
      ans += i - boyCnt[boys[i]] - girlCnt[girls[i]];
      boyCnt[boys[i]]++;
      girlCnt[girls[i]]++;
    }
    cout << ans << "\n";
  }
}
