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
using vi = vector<int>;
using vc = vector<char>;
using vb = vector<bool>;
using ii = pair<int, int>;

#define eb emplace_back

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  // SSSP for each source.
  // Note that it is far more efficient to deal with integers than strings, so
  // map each string to an integer before proceeding.
  int t;
  cin >> t;
  while (t--) {
    int m;
    cin >> m;
    unordered_map<string, int> vertices;
    vector<vi> adj;
    for (int i = 0; i < m; ++i) {
      string u, v;
      cin >> u >> v;
      if (!vertices.count(u)) {
        vertices[u] = vertices.size();
      }
      if (!vertices.count(v)) {
        vertices[v] = vertices.size();
      }
      if (adj.size() < vertices.size()) {
        adj.resize(vertices.size());
      }
      adj[vertices[u]].emplace_back(vertices[v]);
      adj[vertices[v]].emplace_back(vertices[u]);
    }

    int cnt = 0;
    for (int i = 0; i < adj.size(); ++i) {
      queue<int> q;
      q.emplace(i);
      vi dist(adj.size(), 1e9);
      dist[i] = 0;
      int vis = 1;
      while (q.size()) {
        int u = q.front();
        q.pop();

        int ndist = dist[u] + 1;
        for (auto v : adj[u]) {
          if (ndist <= 6 && ndist < dist[v]) {
            q.emplace(v);
            dist[v] = ndist;
            vis++;
          }
        }
      }

      if (vis < adj.size()) {
        ++cnt;
      }
    }

    if (cnt * 20 > adj.size()) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
    }
  }
}
