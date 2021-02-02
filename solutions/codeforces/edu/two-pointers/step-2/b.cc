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
  int64_t S;
  cin >> N >> S;
  vector<int> A(N);

  int ans = INT_MAX;
  int l = 0;
  int64_t sum = 0;
  for (int r = 0; r < N; ++r) {
    cin >> A[r];
    sum += A[r];
    while (sum >= S) {
      sum -= A[l];
      ++l;
    }
    if (l > 0)
      ans = min(ans, r - l + 2);
  }
  cout << (ans == INT_MAX ? -1 : ans);
}
