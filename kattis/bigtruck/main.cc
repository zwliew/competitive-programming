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

  // State space search with Dijkstra's algorithm.
  int n;
  cin >> n;
  vi locations(n);
  for (int &x : locations) cin >> x;
  int m;
  cin >> m;
  vector<vii> adj(n);
  for (int i = 0; i < m; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    --u, --v;
    adj[u].emplace_back(v, w);
    adj[v].emplace_back(u, w);
  }

  priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                 greater<tuple<int, int, int>>>
      q;
  q.emplace(0, 0, locations[0]);
  vi dist(n, 1e9);
  vi items(n, 0);
  dist[0] = 0;
  items[0] = locations[0];
  while (q.size()) {
    auto [d, u, i] = q.top();
    q.pop();

    if (d > dist[u]) continue;
    if (u == n - 1) {
      if (d < dist[u]) {
        dist[u] = d;
        items[u] = i;
      } else if (d == dist[u] && i > items[u]) {
        items[u] = i;
      }
      continue;
    }

    for (auto &[v, w] : adj[u]) {
      int ni = i + locations[v];
      int nd = d + w;
      if (nd < dist[v]) {
        dist[v] = nd;
        items[v] = ni;
        q.emplace(nd, v, ni);
      } else if (nd == dist[v] && ni > items[v]) {
        items[v] = ni;
        q.emplace(nd, v, ni);
      }
    }
  }

  if (dist.back() == 1e9) {
    cout << "impossible";
  } else {
    cout << dist.back() << ' ' << items.back();
  }
}
