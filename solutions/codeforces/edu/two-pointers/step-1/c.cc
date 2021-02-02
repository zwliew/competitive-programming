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
  vector<int> A(N), B(M);
  for (auto& x : A)
    cin >> x;
  for (auto& x : B)
    cin >> x;

  int64_t ans = 0;
  for (int l = 0, i = 0; l < M;) {
    int r = l + 1;
    while (r < M && B[r] == B[l])
      ++r;
    while (i < N && A[i] < B[l])
      ++i;
    int j = i;
    while (j < N && A[j] == B[l])
      ++j;
    ans += (int64_t)(r - l) * (j - i);
    i = j;
    l = r;
  }
  cout << ans;
}
