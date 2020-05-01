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
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

using ll = long long;
using ld = long double;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;
using vc = vector<char>;
using vb = vector<bool>;

#define eb emplace_back

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  const vector<tuple<int, int, int, int>> edges = {
      {0, 2, 1, 0},
      {0, 1, 0, 2},
      {2, 0, 0, 0},
  };
  int h, t;
  while (cin >> h >> t && h && t) {
    queue<ii> q;
    q.emplace(h, t);
    vector<vi> dist(1000, vi(1000, 1e9));
    dist[h][t] = 0;
    while (q.size()) {
      auto [x, y] = q.front();
      q.pop();
      if (!x && !y) {
        cout << dist[x][y] << '\n';
        break;
      }
      for (auto &[dx, dy, rh, rt] : edges) {
        int nx = x - dx;
        int ny = y - dy;
        if (nx < 0 || ny < 0) continue;
        int ndist = dist[x][y] + 1;
        nx += rh;
        ny += rt;
        if (ndist < dist[nx][ny]) {
          q.emplace(nx, ny);
          dist[nx][ny] = ndist;
        }
      }
    }
  }
}
