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

  // SSSP on an unweighted, undirected implicit graph. BFS the state space where
  // the state parameter is simply a bitmask of the current grid.
  int p;
  cin >> p;
  while (p--) {
    int d = 0;
    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 3; ++j) {
        char c;
        cin >> c;
        if (c == '*') {
          d |= 1 << (i * 3 + j);
        }
      }
    }
    vi dist(512, 1e9);
    dist[0] = 0;
    queue<int> q;
    q.emplace(0);
    while (q.size()) {
      int u = q.front();
      q.pop();
      if (u == d) {
        cout << dist[u] << '\n';
        break;
      }

      int ndist = dist[u] + 1;
      for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
          int v = u ^ (1 << (i * 3 + j));
          for (int d = -1; d <= 1; ++d) {
            if (!d) continue;
            int ni = i + d;
            if (ni >= 0 && ni < 3) v ^= (1 << (ni * 3 + j));
            int nj = j + d;
            if (nj >= 0 && nj < 3) v ^= (1 << i * 3 + nj);
          }
          if (ndist < dist[v]) {
            dist[v] = ndist;
            q.emplace(v);
          }
        }
      }
    }
  }
}
