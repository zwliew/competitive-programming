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

  auto solve = []() {
    int N;
    cin >> N;
    
    string first = "989";
    for (int i = 0; i < N && i < 3; ++i) {
      cout << first[i];
    }
    for (int i = 3; i < N; ++i) {
      cout << (i - 3) % 10;
    }
    cout << "\n";
  };

  int T;
  cin >> T;
  while (T--) {
    solve();
  }
}
