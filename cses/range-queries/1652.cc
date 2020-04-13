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

typedef long long ll;
typedef long double ld;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  // Range 2D sum queries on a static 2D array
  // Use a 2D binary indexed tree or 2D prefix sum array
  int n, q;
  cin >> n >> q;

  // 2D prefix sum solution (simpler).
  // Works for static arrays only.
  vector<vector<int>> prefixSums(n + 1, vector<int>(n + 1));
  for (int r = 1; r <= n; ++r) {
    for (int c = 1; c <= n; ++c) {
      char x;
      cin >> x;
      prefixSums[r][c] = prefixSums[r][c - 1] + prefixSums[r - 1][c] -
                         prefixSums[r - 1][c - 1] + (x == '*');
    }
  }
  while (q--) {
    int y1, x1, y2, x2;
    cin >> y1 >> x1 >> y2 >> x2;
    cout << prefixSums[y2][x2] - prefixSums[y1 - 1][x2] -
                prefixSums[y2][x1 - 1] + prefixSums[y1 - 1][x1 - 1]
         << '\n';
  }

  // 2D binary indexed tree solution (more complicated)
  // This is only necessary for 2D range sum queries and updates on a dynamic
  // array.

  // vector<vector<int>> t(n + 1, vector<int>(n + 1)); auto update =
  // [&](int r, int c) {
  //   for (; r <= n; r += r & -r) {
  //     for (int x = c; x <= n; x += x & -x) {
  //       t[r][x]++;
  //     }
  //   }
  // };
  // auto query = [&](int r, int c) {
  //   int res = 0;
  //   for (; r; r -= r & -r) {
  //     for (int x = c; x; x -= x & -x) {
  //       res += t[r][x];
  //     }
  //   }
  //   return res;
  // };
  // for (int r = 1; r <= n; ++r) {
  //   for (int c = 1; c <= n; ++c) {
  //     char x;
  //     cin >> x;
  //     if (x == '*') update(r, c);
  //   }
  // }
  // while (q--) {
  //   int y1, x1, y2, x2;
  //   cin >> y1 >> x1 >> y2 >> x2;
  //   cout << query(y2, x2) - (x1 > 1 ? query(y2, x1 - 1) : 0) -
  //               (y1 > 1 ? query(y1 - 1, x2) : 0) +
  //               (x1 > 1 && y1 > 1 ? query(y1 - 1, x1 - 1) : 0)
  //        << '\n';
  // }
}
