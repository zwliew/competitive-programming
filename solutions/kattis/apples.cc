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

  int h, w;
  cin >> h >> w;
  vector<vector<char>> grid(h, vector<char>(w));
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      cin >> grid[i][j];
    }
  }

  for (int c = 0; c < w; ++c) {
    int j = h - 1;
    for (int i = h - 1; i >= 0; --i) {
      if (grid[i][c] == 'a') {
        grid[i][c] = '.';
        grid[j][c] = 'a';
        --j;
      } else if (grid[i][c] == '#') {
        j = i - 1;
      }
    }
  }

  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      cout << grid[i][j];
    }
    cout << "\n";
  }
}
