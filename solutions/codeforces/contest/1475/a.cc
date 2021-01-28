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
    int64_t N;
    cin >> N;
    // while (N % 2 == 0) {
    //   N /= 2;
    // }
    // if (N > 1) {

    // Editorial solution
    if (N & (N - 1)) {
      cout << "YES";
    } else {
      cout << "NO";
    }
    cout << "\n";
  }
}
