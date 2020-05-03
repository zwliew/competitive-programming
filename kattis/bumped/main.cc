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

  int n, m, f, s, t;
  cin >> n >> m >> f >> s >> t;
  vector<vector<pair<int, ll>>> adj(n);
  vector<vi> flights(n);
  for (int i = 0; i < m; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].emplace_back(v, w);
    adj[v].emplace_back(u, w);
  }

  for (int i = 0; i < f; ++i) {
    int u, v;
    cin >> u >> v;
    flights[u].emplace_back(v);
  }

  vector<vector<ll>> dist(n, vector<ll>(2, 1e18));
  dist[s][0] = 0;
  priority_queue<tuple<ll, int, bool>, vector<tuple<ll, int, bool>>,
                 greater<tuple<ll, int, bool>>>
      q;
  q.emplace(0, s, 0);
  while (q.size()) {
    auto [d, u, b] = q.top();
    q.pop();

    if (d > dist[u][b]) continue;

    if (u == t) {
      cout << d;
      return 0;
    }

    for (auto &[v, w] : adj[u]) {
      ll nd = d + w;
      if (nd < dist[v][b]) {
        dist[v][b] = nd;
        q.emplace(nd, v, b);
      }
    }

    if (!b) {
      for (auto v : flights[u]) {
        if (d < dist[v][1]) {
          dist[v][1] = d;
          q.emplace(d, v, 1);
        }
      }
    }
  }
}
