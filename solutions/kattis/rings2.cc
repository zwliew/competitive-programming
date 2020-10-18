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
  queue<pair<int, int>> q;
  vector<vector<int>> grid(h, vector<int>(w));
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      char c;
      cin >> c;
      if (c == 'T') {
        grid[i][j] = -1;
      }
    }
  }

  auto ok = [&](int r, int c) { return r >= 0 && r < h && c >= 0 && c < w; };

  int maxRing = 0;
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      if (!grid[i][j])
        continue;
      bool bordered = false;
      for (int dr = -1; dr <= 1; ++dr) {
        for (int dc = -1; dc <= 1; ++dc) {
          if (dr && dc)
            continue;
          if (ok(i + dr, j + dc) && !grid[i + dr][j + dc]) {
            bordered = true;
            break;
          }
          if (bordered) {
            break;
          }
        }
      }
      if (!i || !j || i == h - 1 || j == w - 1 || bordered) {
        q.emplace(i, j);
        grid[i][j] = 1;
        maxRing = 1;
      }
    }
  }

  while (q.size()) {
    auto [r, c] = q.front();
    q.pop();

    for (int dr = -1; dr <= 1; ++dr) {
      for (int dc = -1; dc <= 1; ++dc) {
        if (dc && dr)
          continue;
        int nr = r + dr;
        int nc = c + dc;
        if (ok(nr, nc) && grid[nr][nc] == -1) {
          q.emplace(nr, nc);
          grid[nr][nc] = grid[r][c] + 1;
          maxRing = grid[nr][nc];
        }
      }
    }
  }

  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      if (maxRing < 10) {
        cout << ".";
      } else if (grid[i][j] < 10) {
        cout << "..";
      } else {
        cout << ".";
      }
      if (!grid[i][j]) {
        cout << ".";
      } else {
        cout << grid[i][j];
      }
    }
    cout << "\n";
  }
}
