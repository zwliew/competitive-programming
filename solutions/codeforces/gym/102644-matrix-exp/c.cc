/*
ID: zhaowei10
TASK:
LANG: C++14
*/
#include "bits/stdc++.h"

using namespace std;

#ifdef LOCAL
#include "../../_library/cc/debug.h"
#define FILE "test"
#else
#define debug(...) 0
#define FILE ""
#endif

inline vector<vector<int>> matmult(vector<vector<int>>& a,
                                   vector<vector<int>>& b,
                                   const int m) {
  vector<vector<int>> res = {{0, 0}, {0, 0}};
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 2; ++j) {
      for (int k = 0; k < 2; ++k) {
        res[i][k] += ((int64_t)a[i][j] * b[j][k]) % m;
        res[i][k] %= m;
      }
    }
  }
  return res;
}

inline int fib(int64_t n, int m) {
  vector<vector<int>> res = {{1, 0}, {0, 1}};
  vector<vector<int>> mat = {{0, 1}, {1, 1}};
  while (n) {
    if (n & 1) {
      res = matmult(res, mat, m);
    }
    mat = matmult(mat, mat, m);
    n >>= 1;
  }
  return res[1][0];
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int64_t n;
  cin >> n;
  cout << fib(n, 1e9 + 7);
}
