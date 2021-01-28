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
  vector<int> cows(N), lims(N);
  for (int i = 0; i < N; ++i) {
    cin >> cows[i];
  }
  for (int i = 0; i < N; ++i) {
    cin >> lims[i];
  }
  sort(cows.rbegin(), cows.rend());
  sort(lims.rbegin(), lims.rend());

  int64_t ans = 1;
  for (int i = 0, j = 0; i < N; ++i) {
    for (; j < N && lims[j] >= cows[i]; ++j)
      ;
    ans *= j - i;
  }
  cout << ans;
}
