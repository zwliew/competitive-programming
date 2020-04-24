#include <stdio.h>

#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <deque>
#include <fstream>
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

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int n, m, q, s;
  while (cin >> n >> m >> q >> s && (n || m || q || s)) {
    vector<vector<pair<ll, int>>> adj(n);
    for (int i = 0; i < m; ++i) {
      int u, v, w;
      cin >> u >> v >> w;
      adj[u].emplace_back(w, v);
    }
    vector<int> outputs;
    for (int i = 0; i < q; ++i) {
      int e;
      cin >> e;
      outputs.emplace_back(e);
    }

    unordered_map<int, ll> distances = {{s, 0}};
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>>
        pq;
    pq.emplace(0, s);
    while (pq.size()) {
      auto [w, u] = pq.top();
      pq.pop();
      if (distances.count(u) && distances[u] < w) {
        continue;
      }
      distances[u] = w;
      for (auto &[vw, v] : adj[u]) {
        if (!distances.count(v) || distances[v] > w + vw) {
          distances[v] = w + vw;
          pq.emplace(vw + w, v);
        }
      }
    }

    for (int x : outputs) {
      if (distances.count(x)) {
        cout << distances[x] << '\n';
      } else {
        cout << "Impossible\n";
      }
    }

    cout << '\n';
  }
}
