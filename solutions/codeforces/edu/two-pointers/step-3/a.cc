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

  int N;
  int64_t P;
  cin >> N >> P;
  vector<int> A(N);
  for (auto &x : A) cin >> x;

  int64_t total = accumulate(A.begin(), A.end(), (int64_t)0);
  int loops = 0;
  if (total < P) {
    loops = P / total;
    P %= total;
  }

  A.resize(N * 2);
  for (int i = 0; i < N; ++i) {
    A[N + i] = A[i];
  }

  int bestL = 0;
  int bestCnt = INT_MAX;
  int64_t curSum = 0;
  for (int r = 0, l = 0; r < N * 2; ++r) {
    curSum += A[r];
    for (; curSum >= P; curSum -= A[l], ++l);
    if (l && bestCnt > r - l + 2) {
      bestCnt = r - l + 2;
      bestL = l - 1;
    }
  }
  cout << bestL + 1 << " " << bestCnt + (int64_t)loops * N;
}
