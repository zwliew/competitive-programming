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

  string best;
  for (int i = 0; i < h; ++i) {
    int l = 0, r = 0;
    while (l < w) {
      string s;
      while (r < w && grid[i][r] != '#') {
        s += grid[i][r];
        ++r;
      }
      if (s.size() > 1 && (best.empty() || s < best)) {
        best = s;
      }
      l = r + 1;
      r = l;
    }
  }

  for (int i = 0; i < w; ++i) {
    int t = 0, b = 0;
    while (t < h) {
      string s;
      while (b < h && grid[b][i] != '#') {
        s += grid[b][i];
        ++b;
      }
      if (s.size() > 1 && (best.empty() || s < best)) {
        best = s;
      }
      t = b + 1;
      b = t;
    }
  }
  cout << best;
}
