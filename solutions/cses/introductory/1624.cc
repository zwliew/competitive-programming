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

int count(array<bitset<8>, 8>& allowed,
          bitset<8>& cols,
          bitset<15>& diag1,
          bitset<15>& diag2,
          int row) {
  if (row == 8)
    return 1;

  int cnt = 0;
  for (int col = 0; col < 8; ++col) {
    if (!allowed[row][col] || cols[col] || diag1[col + row] ||
        diag2[col + 7 - row])
      continue;
    cols[col] = diag1[col + row] = diag2[col + 7 - row] = true;
    cnt += count(allowed, cols, diag1, diag2, row + 1);
    cols[col] = diag1[col + row] = diag2[col + 7 - row] = false;
  }
  return cnt;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  array<bitset<8>, 8> allowed;
  for (int i = 0; i < 8; ++i) {
    for (int j = 0; j < 8; ++j) {
      char c;
      cin >> c;
      allowed[i][j] = c == '.';
    }
  }

  // Recursive backtracking solution.
  // Idea: build the column positions 1 by 1.
  bitset<8> cols;
  bitset<15> diag1, diag2;
  cout << count(allowed, cols, diag1, diag2, 0);

  // Alternative iterative complete search solution.
  // Idea: iterate through all 8! permutations
  // vector<int> cols(8);
  // iota(cols.begin(), cols.end(), 0);
  // int cnt = 0;
  // do {
  //   bool ok = true;
  //   bitset<15> diag1, diag2;
  //   for (int i = 0; i < 8; ++i) {
  //     if (!allowed[i][cols[i]]) {
  //       ok = false;
  //       break;
  //     }
  //     if (diag1[cols[i] + i] || diag2[7 - i + cols[i]]) {
  //       ok = false;
  //       break;
  //     }
  //     diag1[cols[i] + i] = true;
  //     diag2[7 - i + cols[i]] = true;
  //   }
  //   if (ok) {
  //     ++cnt;
  //   }
  // } while (next_permutation(cols.begin(), cols.end()));
  // cout << cnt;
}
