#include <bits/stdc++.h>
using namespace std;
#define debug(...) 0
#ifdef LOCAL
#include "../../_library/cc/debug.h"
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
#if defined(FILE) && !defined(LOCAL)
  freopen(FILE ".in", "r", stdin), freopen(FILE ".out", "w", stdout);
#endif

  int B, C, D, L;
  cin >> B >> C >> D >> L;
  bool found = false;
  for (int i = 0; i * B <= L; ++i) {
    for (int j = 0; j * C + i * B <= L; ++j) {
      int k = L - i * B - j * C;
      if (k % D == 0) {
        cout << i << " " << j << " " << k / D << "\n";
        found = true;
      }
    }
  }
  if (!found) {
    cout << "impossible";
  }
}
