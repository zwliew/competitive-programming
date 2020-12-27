/*
ID: zhaowei10
LANG: C++14
TASK:
*/
#include <bits/stdc++.h>
using namespace std;
#define debug(...) 0
#ifdef LOCAL
#include "../../_library/cc/debug.h"
#endif
// #define FILE "milk2"

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
#if defined(FILE) && !defined(LOCAL)
  freopen(FILE ".in", "r", stdin), freopen(FILE ".out", "w", stdout);
#endif

  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    unordered_map<int, int> last;
    int64_t ans = 0;
    for (int i = 0; i < N; ++i) {
      int x;
      cin >> x;
      if (last.count(x)) {
        ans += i - last[x];
      }
      last[x] = i;
    }
    cout << ans << "\n";
  }
}
