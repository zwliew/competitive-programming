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

  int T;
  cin >> T;
  while (T--) {
    string S;
    cin >> S;
    int cnt = 0;
    for (int i = 1; i < S.size(); ++i) {
      if (S[i] == S[i - 1] || (i >= 2 && S[i] == S[i - 2])) {
        S[i] = '-';
        ++cnt;
      }
    }
    cout << cnt << "\n";
  }
}
