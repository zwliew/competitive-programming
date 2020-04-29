#include <stdio.h>

#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <deque>
#include <fstream>
#include <functional>
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

  int r, c, zr, zc;
  cin >> r >> c >> zr >> zc;

  vector<vector<char>> ans(r * zr, vector<char>(c * zc));
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      char x;
      cin >> x;
      for (int k = 0; k < zr; ++k) {
        for (int l = 0; l < zc; ++l) {
          ans[i * zr + k][j * zc + l] = x;
        }
      }
    }
  }

  for (int i = 0; i < r * zr; ++i) {
    for (int j = 0; j < c * zc; ++j) {
      cout << ans[i][j];
    }
    cout << '\n';
  }
}
