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
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <random>
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

  const vector<array<int, 2>> edges = {
      {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1},
  };

  int h, w;
  while (cin >> h >> w && w && h) {
    vector<vector<int>> grid(h, vector<int>(w));
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        char c;
        cin >> c;
        grid[i][j] = c - '0';
      }
    }

    priority_queue<array<int, 3>> pq;
    vector<vector<int>> d(h, vector<int>(w, 1e9)), p(h, vector<int>(w, -1));
    for (int i = 0; i < w; ++i) {
      d[0][i] = grid[0][i];
      pq.push({-grid[0][i], 0, i});
    }

    while (pq.size()) {
      auto u = pq.top();
      pq.pop();
      u[0] = -u[0];
      if (u[0] > d[u[1]][u[2]]) {
        continue;
      }
      for (int i = 0; i < 8; ++i) {
        int r = edges[i][0] + u[1];
        int c = edges[i][1] + u[2];
        if (r >= 0 && c >= 0 && r < h && c < w && d[r][c] > u[0] + grid[r][c]) {
          d[r][c] = u[0] + grid[r][c];
          pq.push({-d[r][c], r, c});
          p[r][c] = i;
        }
      }
    }

    debug(p);
    debug(d);

    int c = 0;
    for (int i = 1; i < w; ++i) {
      if (d[h - 1][i] < d[h - 1][c]) {
        c = i;
      }
    }

    debug(c);

    vector<vector<bool>> fractured(h, vector<bool>(w));
    int r = h - 1;
    while (p[r][c] != -1) {
      fractured[r][c] = true;
      auto& e = edges[p[r][c]];
      r -= e[0];
      c -= e[1];
    }
    fractured[r][c] = true;

    debug(fractured);

    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        if (fractured[i][j]) {
          cout << " ";
        } else {
          cout << grid[i][j];
        }
      }
      cout << "\n";
    }
    cout << "\n";
  }
}
