#include <stdio.h>

#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <deque>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

using ll = long long;
using ld = long double;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int t;
  cin >> t;
  while (t--) {
    vector<vector<int>> grid(9, vector<int>(9));
    for (int i = 0; i < 9; ++i) {
      for (int j = 0; j < 9; ++j) {
        char c;
        cin >> c;
        grid[i][j] = c - '0';
      }
    }
    cerr << '\n';
    for (int i = 0; i < 3; ++i) {
      for (int row = i * 3, col = i, cnt = 0; cnt < 3; ++row, col += 3, ++cnt) {
        grid[row][col] =
            ((col % 3 < 2) ? grid[row][col + 1] : grid[row][col - 1]);
      }
    }
    for (int i = 0; i < 9; ++i) {
      for (int j = 0; j < 9; ++j) {
        cout << grid[i][j];
      }
      cout << '\n';
    }
  }
}
