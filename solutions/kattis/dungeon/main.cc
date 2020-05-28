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
using vi = vector<int>;
using vb = vector<bool>;
using ii = pair<int, int>;

#define eb emplace_back

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  // SSSP on a 3D grid.
  int l, r, c;
  while (cin >> l >> r >> c && l && r && c) {
    int ex, ey, ez;
    vector<vector<vb>> grid(l, vector<vb>(r, vb(c)));
    vector<vector<vi>> dist(l, vector<vi>(r, vi(c, 1e9)));
    queue<tuple<int, int, int>> q;
    for (int i = 0; i < l; ++i) {
      for (int j = 0; j < r; ++j) {
        for (int k = 0; k < c; ++k) {
          char x;
          cin >> x;
          grid[i][j][k] = x != '#';
          if (x == 'S') {
            q.emplace(i, j, k);
            dist[i][j][k] = 0;
          } else if (x == 'E') {
            ex = i;
            ey = j;
            ez = k;
          }
        }
      }
    }

    bool found = 0;
    while (q.size()) {
      auto [x, y, z] = q.front();
      q.pop();

      if (x == ex && y == ey && z == ez) {
        cout << "Escaped in " << dist[x][y][z] << " minute(s).\n";
        found = 1;
        break;
      }

      int ndist = dist[x][y][z] + 1;
      for (int d : {1, -1}) {
        int nx = x + d;
        int ny = y + d;
        int nz = z + d;

        if (nx >= 0 && nx < l && grid[nx][y][z] && ndist < dist[nx][y][z]) {
          q.emplace(nx, y, z);
          dist[nx][y][z] = ndist;
        }

        if (ny >= 0 && ny < r && grid[x][ny][z] && ndist < dist[x][ny][z]) {
          q.emplace(x, ny, z);
          dist[x][ny][z] = ndist;
        }

        if (nz >= 0 && nz < c && grid[x][y][nz] && ndist < dist[x][y][nz]) {
          q.emplace(x, y, nz);
          dist[x][y][nz] = ndist;
        }
      }
    }

    if (!found) {
      cout << "Trapped!\n";
    }
  }
}
