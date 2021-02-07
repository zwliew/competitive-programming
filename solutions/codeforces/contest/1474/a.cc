#include <bits/stdc++.h>
using namespace std;
#define debug(...) 0
#ifdef LOCAL
#include "../../_library/cc/debug.h"
#endif
// #define FILE

int main()
{
  cin.tie(nullptr)->sync_with_stdio(false);
#if defined(FILE) && !defined(LOCAL)
  freopen(FILE ".in", "r", stdin), freopen(FILE ".out", "w", stdout);
#endif

  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    vector<int> B(N);
    for (auto &x : B) {
      char c;
      cin >> c;
      x = c;
    }

    int prev = 0;
    for (int i = 0; i < N; ++i) {
      for (int j = 1; j >= 0; --j) {
        int d = B[i] + j;
        if (prev != d) {
          prev = d;
          cout << j;
          break;
        }
      }
    }

    cout << "\n";
  }
}
