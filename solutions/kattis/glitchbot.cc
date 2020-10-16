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
#define FILE "feast"
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  // Try every possible change in moves
  int x, y, n;
  cin >> x >> y >> n;

  unordered_map<string, int> mp = {{"Forward", 0}, {"Left", 1}, {"Right", 2}};
  vector<string> rmp = {"Forward", "Left", "Right"};
  vector<pair<int, int>> moves = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};

  vector<int> instructions(n);
  for (auto& x : instructions) {
    string s;
    cin >> s;
    x = mp[s];
  }

  auto updateState = [&](int& x, int& y, int& dir, int instruction) {
    if (!instruction) {
      x += moves[dir].first;
      y += moves[dir].second;
    } else if (instruction == 1) {
      dir = (dir + 1) % 4;
    } else {
      dir = (dir + 3) % 4;
    }
  };

  int dir = 0;
  int cx = 0, cy = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 3; ++j) {
      if (j == instructions[i])
        continue;
      int nx = cx, ny = cy;
      int ndir = dir;
      updateState(nx, ny, ndir, j);

      for (int k = i + 1; k < n; ++k) {
        updateState(nx, ny, ndir, instructions[k]);
      }

      if (nx == x && ny == y) {
        cout << i + 1 << ' ' << rmp[j];
        return 0;
      }
    }
    updateState(cx, cy, dir, instructions[i]);
  }
}
