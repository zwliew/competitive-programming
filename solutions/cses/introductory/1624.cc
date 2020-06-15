/*
ID: zhaowei10
TASK:
LANG: C++14
*/
#include "bits/extc++.h"

using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;

#ifdef LOCAL
#include "../../_library/cpp/debug.h"
#define FILE "test"
#else
#define debug(...) 0
#define FILE ""
#endif

int count(vector<vector<bool>> &reserved, vector<int> &cols, int row) {
  if (row == 8) {
    return 1;
  }

  int cnt = 0;
  for (int i = 0; i < 8; ++i) {
    if (reserved[row][i]) continue;
    bool ok = true;
    for (int j = 0; j < row && ok; ++j) {
      if (cols[j] == i || abs(row - j) == abs(cols[j] - i)) {
        ok = false;
      }
    }

    if (ok) {
      cols[row] = i;
      cnt += count(reserved, cols, row + 1);
    }
  }
  return cnt;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  vector<int> cols(8);
  vector<vector<bool>> reserved(8, vector<bool>(8));
  for (int i = 0; i < 8; ++i) {
    for (int j = 0; j < 8; ++j) {
      char c;
      cin >> c;
      reserved[i][j] = c == '*';
    }
  }
  cout << count(reserved, cols, 0);
}
