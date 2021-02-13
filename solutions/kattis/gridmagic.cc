#include "bits/stdc++.h"
using namespace std;
#define debug(...) 0
#ifdef LOCAL
#include "../../_library/cc/debug.h"
#endif
// #define FILE

int N, M;
bool isPrime(int N) {
  if (N <= 3) {
    return N > 1;
  }
  for (int d = 2; d * d <= N; ++d) {
    if (N % d == 0) {
      return false;
    }
  }
  return true;
}
int solve(vector<vector<int>> &rowPref, vector<vector<int>> &colPref, int r, int c) {
  if (c == M) {
    return solve(rowPref, colPref, r + 1, 0);
  }
  if (r == N) {
    return 1;
  }
  int cnt = 0;
  int rowPrefix = c ? rowPref[r][c - 1] : 0;
  int colPrefix = r ? colPref[r - 1][c] : 0;
  for (int i = 0; i < 10; ++i) {
    int nxtRowPrefix = rowPrefix * 10 + i;
    int nxtColPrefix = colPrefix * 10 + i;
    if (isPrime(nxtRowPrefix) && isPrime(nxtColPrefix)) {
      rowPref[r][c] = nxtRowPrefix;
      colPref[r][c] = nxtColPrefix;
      cnt += solve(rowPref, colPref, r, c + 1);
    }
  }
  return cnt;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
#if defined(FILE) && !defined(LOCAL)
  freopen(FILE ".in", "r", stdin), freopen(FILE ".out", "w", stdout);
#endif

  cin >> N >> M;
  vector<vector<int>> rowPref(N, vector<int>(M)), colPref;
  colPref = rowPref;
  cout << solve(rowPref, colPref, 0, 0) << "\n";
}
