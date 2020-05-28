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

  // SSSP on an undirected weighted graph. Use state-space search where the
  // state parameters are (current city, fuel in tank).
  int n, m;
  cin >> n >> m;
  vi p(n);
  for (int &x : p) cin >> x;
  vector<vii> adj(n);
  for (int i = 0; i < m; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].emplace_back(v, w);
    adj[v].emplace_back(u, w);
  }

  int q;
  cin >> q;
  while (q--) {
    int s, e, c;
    cin >> c >> s >> e;
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                   greater<tuple<int, int, int>>>
        q;
    q.emplace(0, s, 0);
    vector<vi> dist(1000, vi(101, 1e9));
    dist[s][0] = 0;
    bool found = 0;
    while (q.size()) {
      auto [d, u, l] = q.top();
      q.pop();
      if (d > dist[u][l]) continue;

      if (u == e) {
        cout << d << '\n';
        found = 1;
        break;
      }

      if (l < c && d + p[u] < dist[u][l + 1]) {
        q.emplace(d + p[u], u, l + 1);
        dist[u][l + 1] = d + p[u];
      }

      for (auto [v, w] : adj[u]) {
        if (l >= w && d < dist[v][l - w]) {
          q.emplace(d, v, l - w);
          dist[v][l - w] = d;
        }
      }
    }

    if (!found) {
      cout << "impossible\n";
    }
  }
}
