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

  int w, h;
  int ti = 1;
  while (cin >> w >> h && (w || h)) {
    cout << "HOUSE " << ti++ << "\n";
    vector<vector<char>> grid(h, vector<char>(w));
    pair<int, int> start;
    pair<int, int> dir;
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        cin >> grid[i][j];
        if (grid[i][j] == '*') {
          start = {i, j};
          if (j == 0) {
            dir = {0, 1};
          } else if (j == w - 1) {
            dir = {0, -1};
          } else if (i == 0) {
            dir = {1, 0};
          } else {
            dir = {-1, 0};
          }
        }
      }
    }

    do {
      start = {start.first + dir.first, start.second + dir.second};
      if (grid[start.first][start.second] == '/') {
        dir = {dir.second * -1, dir.first * -1};
      } else if (grid[start.first][start.second] == '\\') {
        dir = {dir.second, dir.first};
      }
    } while (start.first > 0 && start.first < h - 1 && start.second > 0 &&
             start.second < w - 1);

    grid[start.first][start.second] = '&';
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        cout << grid[i][j];
      }
      cout << "\n";
    }
  }
}
