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

  vector<vector<int>> grid(4, vector<int>(4));
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      cin >> grid[i][j];
    }
  }

  auto rotateMat = [&]() {
    for (int i = 0; i < 2; ++i) {
      swap(grid[i], grid[3 - i]);
    }
    for (int i = 0; i < 4; ++i) {
      for (int j = 0; j <= i; ++j) {
        swap(grid[i][j], grid[j][i]);
      }
    }
  };

  int dir;
  cin >> dir;
  vector<int> requiredRotations = {0, 3, 2, 1};
  for (int i = 0; i < requiredRotations[dir]; ++i) {
    rotateMat();
  }

  for (int i = 0; i < 4; ++i) {
    vector<int> res(4);
    int idx = 0;
    for (int j = 0; j < 4; ++j) {
      if (grid[i][j]) {
        if (res[idx] == grid[i][j]) {
          res[idx] *= 2;
          ++idx;
        } else {
          if (res[idx])
            ++idx;
          res[idx] = grid[i][j];
        }
      }
    }
    grid[i] = res;
  }

  for (int i = 0; i < (4 - requiredRotations[dir]) % 4; ++i) {
    rotateMat();
  }

  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      cout << grid[i][j] << " ";
    }
    cout << "\n";
  }
}
