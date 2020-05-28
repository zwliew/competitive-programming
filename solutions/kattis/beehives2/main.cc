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

  // Find the shortest length cycle in an undirected unweighted graph.
  int n, m;
  cin >> n >> m;
  vector<vi> adj(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
  }

  int ans = 1e9;
  for (int i = 0; i < n; ++i) {
    queue<int> q;
    vi dist(n, 1e9);
    vi parents(n, -1);
    dist[i] = 0;
    bool found = 0;
    q.emplace(i);
    while (q.size() && !found) {
      int u = q.front();
      q.pop();
      for (int v : adj[u]) {
        if (v == parents[u]) continue;
        int ndist = dist[u] + 1;
        if (dist[v] < ndist) {
          ans = min(ans, ndist + dist[v]);
          found = 1;
          break;
        }
        dist[v] = ndist;
        parents[v] = u;
        q.emplace(v);
      }
    }
  }

  if (ans < 1e9)
    cout << ans;
  else
    cout << "impossible";
}
