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

  int N, M;
  cin >> N >> M;
  vector<int> A(N);
  for (auto& x : A)
    cin >> x;
  for (int i = 0, j = 0; i < M; ++i) {
    int x;
    cin >> x;
    while (j < N && A[j] < x)
      ++j;
    cout << j << " ";
  }
}
