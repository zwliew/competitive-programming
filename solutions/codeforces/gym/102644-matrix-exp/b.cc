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

vector<vector<int64_t>> matmult(vector<vector<int64_t>> a,
                                vector<vector<int64_t>> b,
                                const int64_t mod) {
  vector<vector<int64_t>> res = {{0, 0}, {0, 0}};
  for (int64_t k = 0; k < 2; ++k) {
    for (int64_t i = 0; i < 2; ++i) {
      for (int64_t j = 0; j < 2; ++j) {
        res[i][j] += a[i][k] * b[k][j];
        res[i][j] %= mod;
      }
    }
  }
  return res;
}

vector<vector<int64_t>> matpow(vector<vector<int64_t>> mat,
                               int64_t n,
                               const int64_t mod) {
  vector<vector<int64_t>> res = {{1, 0}, {0, 1}};
  while (n) {
    if (n & 1) {
      res = matmult(res, mat, mod);
    }
    n >>= 1;
    mat = matmult(mat, mat, mod);
  }
  return res;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int64_t n;
  cin >> n;
  vector<vector<int64_t>> mat = {
      {19, 7},
      {6, 20},
  };
  cout << matpow(mat, n, 1e9 + 7)[0][0] << '\n';
}