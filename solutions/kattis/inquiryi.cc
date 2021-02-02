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

  int N;
  cin >> N;
  vector<int> A(N);
  int64_t sum = 0, prod = 0;
  for (auto& x : A) {
    cin >> x;
    sum += x;
  }

  int64_t ans = 0;
  for (int i = 0; i < N; ++i) {
    ans = max(ans, sum * prod);
    sum -= A[i];
    prod += A[i] * A[i];
  }
  cout << ans;
}
