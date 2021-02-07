#include <bits/stdc++.h>
using namespace std;
#define debug(...) 0
#ifdef LOCAL
#include "../../_library/cc/debug.h"
#endif
// #define FILE

int main() { cin.tie(nullptr)->sync_with_stdio(false);
#if defined(FILE) && !defined(LOCAL)
  freopen(FILE ".in", "r", stdin), freopen(FILE ".out", "w", stdout);
#endif

  int N;
  cin >> N;
  vector<int> X(N);
  for (auto &x : X) cin >> x;
  sort(X.begin(), X.end());

  int64_t sum = 0;
  for (int x : X) {
    // smallest sum < k < x?
    if (x > sum + 1) {
      cout << sum + 1;
      return 0;
    }
    sum += x;
  }
  cout << sum + 1;
}
