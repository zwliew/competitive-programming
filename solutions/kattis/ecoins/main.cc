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

  int n;
  cin >> n;
  while (n--) {
    int m, s;
    cin >> m >> s;
    vector<ii> edges(m);
    for (int i = 0; i < m; ++i) {
      int x, y;
      cin >> x >> y;
      edges[i] = {x, y};
    }

    vector<vi> dist(s + 1, vi(s + 1, 1e9));
    queue<ii> q;
    q.emplace(0, 0);
    dist[0][0] = 0;
    bool found = 0;
    while (q.size()) {
      auto [x, y] = q.front();
      q.pop();

      if (x * x + y * y == s * s) {
        cout << dist[x][y] << '\n';
        found = 1;
        break;
      }

      for (auto [dx, dy] : edges) {
        int nx = x + dx;
        int ny = y + dy;
        if (nx * nx + ny * ny <= s * s && dist[x][y] + 1 < dist[nx][ny]) {
          dist[nx][ny] = dist[x][y] + 1;
          q.emplace(nx, ny);
        }
      }
    }

    if (!found) cout << "not possible\n";
  }
}
