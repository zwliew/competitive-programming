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

  // SSSP on a complete, weighted, undirected graph. There are no negative
  // cycles (or even edges) so we can use Dijkstra's algorithm.
  // Alternatively, use Bellman-Ford's algorithm as the graph is small (V <=
  // 1000).
  int n, s, t;
  cin >> n >> s >> t;
  vector<vi> adj(n, vi(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> adj[i][j];
    }
  }

  priority_queue<ii, vii, greater<ii>> q;
  q.emplace(0, s);
  vi dist(n, 1e9);
  dist[s] = 0;
  while (q.size()) {
    auto [d, u] = q.top();
    q.pop();
    if (u == t) {
      cout << d;
      return 0;
    }
    for (int v = 0; v < n; ++v) {
      int nd = d + adj[u][v];
      if (nd < dist[v]) {
        q.emplace(nd, v);
        dist[v] = nd;
      }
    }
  }
}
