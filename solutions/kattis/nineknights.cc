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
// #include "bits/stdc++.h"

using namespace std;

#ifdef LOCAL
#include "../../_library/cc/debug.h"
#define FILE "test"
#else
#define debug(...) 0
#define FILE "cowjog"
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  // Check for conflicts between every pair of knights
  const vector<pair<int, int>> moves = {
      {-1, -2}, {1, -2}, {-1, 2}, {1, 2}, {-2, -1}, {-2, 1}, {2, -1}, {2, 1},
  };
  vector<pair<int, int>> knights;
  for (int i = 0; i < 5; ++i) {
    for (int j = 0; j < 5; ++j) {
      char x;
      cin >> x;
      if (x == 'k') {
        for (auto& [r, c] : knights) {
          for (auto& [dr, dc] : moves) {
            if (r + dr == i && c + dc == j) {
              cout << "invalid";
              return 0;
            }
          }
        }
        knights.emplace_back(i, j);
      }
    }
  }
  cout << (knights.size() == 9 ? "valid" : "invalid");
}
