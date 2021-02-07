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
    int px, py;
    string s;
    cin >> px >> py >> s;
    for (char c : s) {
      if (c == 'U' && py > 0) {
        --py;
      } else if (c == 'D' && py < 0) {
        ++py;
      } else if (c == 'L' && px < 0) {
        ++px;
      } else if (c == 'R' && px > 0) {
        --px;
      }
    }
    cout << (!py && !px ? "yes" : "no") << "\n";
  }
}
