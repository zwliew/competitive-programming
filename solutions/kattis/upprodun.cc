#include <bits/stdc++.h>
using namespace std;
#define debug(...) 0
#ifdef LOCAL
#include "../../_library/cc/debug.h"
#endif
// #define FILE ""

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
#if defined(FILE) && !defined(LOCAL)
  freopen(FILE ".in", "r", stdin), freopen(FILE ".out", "w", stdout);
#endif

  int N, M;
  cin >> N >> M;
  int rem = M % N;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M / N + (i < rem); ++j) {
      cout << '*';
    }
    cout << "\n";
  }
}
