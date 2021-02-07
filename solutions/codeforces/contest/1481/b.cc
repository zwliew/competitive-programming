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

  int T;
  cin >> T;
  while (T--) {
    int N, K;
    cin >> N >> K;
    vector<int> H(N);
    for (auto &x : H) cin >> x;

    int found = N;
    while (K > 0 && found != -1) {
      found = -1;
      for (int i = 0; found == -1 && i < N - 1; ++i) {
        if (H[i + 1] > H[i]) {
          int d = H[i + 1] - H[i];
          if (i) {
            d = min(d, H[i - 1] - H[i] + 1);
          }
          K -= d;
          H[i] += d;
          found = i + 1;
        }
      }
    }
   cout << found << "\n";
  }
}
