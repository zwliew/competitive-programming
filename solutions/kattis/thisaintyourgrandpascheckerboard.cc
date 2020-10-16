#include <algorithm>
#include <array>
#include <bitset>
#include <chrono>
#include <climits>
#include <cmath>
#include <cstring>
#include <deque>
#include <ext/pb_ds/assoc_container.hpp>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#ifdef LOCAL
#include "../../_library/cc/debug.h"
#define FILE "test"
#else
#define debug(...) 0
#define FILE ""
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int n;
  cin >> n;
  vector<vector<char>> grid(n, vector<char>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> grid[i][j];
    }
  }

  for (int i = 0; i < n; ++i) {
    int rowCnt = 0, colCnt = 0;
    for (int j = 0; j < n; ++j) {
      rowCnt += grid[i][j] == 'B';
      colCnt += grid[j][i] == 'B';
      if (j >= 2) {
        if ((grid[i][j - 1] == grid[i][j] && grid[i][j - 2] == grid[i][j]) ||
            (grid[j - 1][i] == grid[j][i] && grid[j - 2][i] == grid[j][i])) {
          cout << 0;
          return 0;
        }
      }
    }
    if (rowCnt * 2 != n || colCnt * 2 != n) {
      cout << 0;
      return 0;
    }
  }
  cout << 1;
}
