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

  int h, w, n, m;
  cin >> h >> w >> n >> m;
  vector<vector<int>> grid(h, vector<int>(w));
  vector<vector<int>> kernel(n, vector<int>(m));
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      cin >> grid[i][j];
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> kernel[i][j];
    }
  }

  vector<vector<int>> res(h - n + 1, vector<int>(w - m + 1));
  for (int i = 0; i < h - n + 1; ++i) {
    for (int j = 0; j < w - m + 1; ++j) {
      int cur = 0;
      for (int k = 0; k < n; ++k) {
        for (int l = 0; l < m; ++l) {
          cur += kernel[n - k - 1][m - l - 1] * grid[i + k][j + l];
        }
      }
      cout << cur << " ";
    }
    cout << "\n";
  }
}
