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

// #define LOCAL
#ifdef LOCAL
#define debug(...) cerr << '[' << #__VA_ARGS__ << "]:", _debug(__VA_ARGS__)
#else
#define debug(...) 0
#endif

string to_string(string s) { return '"' + s + '"'; }
string to_string(const char *s) { return to_string((string)s); }
string to_string(bool b) { return (b ? "true" : "false"); }
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += '}';
  return res;
}

void _debug() { cerr << '\n'; }
template <typename Head, typename... Tail>
void _debug(Head H, Tail... T) {
  cerr << ' ' << to_string(H);
  _debug(T...);
}

#define eb emplace_back

using ll = long long;
using ld = long double;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;
using vc = vector<char>;
using vb = vector<bool>;

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
  vi dist(n, 1e9);
  dist[s] = 0;

  // Solutuon using Dijkstra's algorithm (0.07s)
  // priority_queue<ii, vii, greater<ii>> q;
  // q.emplace(0, s);
  // while (q.size()) {
  //   auto [d, u] = q.top();
  //   q.pop();
  //   if (u == t) {
  //     cout << d;
  //     return 0;
  //   }
  //   if (d > dist[u]) continue;
  //   for (int v = 0; v < n; ++v) {
  //     int nd = d + adj[u][v];
  //     if (nd < dist[v]) {
  //       q.emplace(nd, v);
  //       dist[v] = nd;
  //     }
  //   }
  // }

  // Alternative solution using Bellman-Ford's algorithm. (0.07s using the
  // optimized version where we break early if there are no more relaxations.
  // With the un-optimized version, the program ran in 0.85-1.23s)
  // bool relaxed = 1;
  // while (relaxed) {
  //   relaxed = 0;
  //   for (int u = 0; u < n; ++u) {
  //     for (int v = 0; v < n; ++v) {
  //       if (dist[u] + adj[u][v] < dist[v]) {
  //         dist[v] = dist[u] + adj[u][v];
  //         relaxed = 1;
  //       }
  //     }
  //   }
  // }
  // cout << dist[t];

  // Alternative solution using Shortest Path Faster Algorithm. (0.07s)
  queue<int> q;
  vb queued(n);
  q.emplace(s);
  queued[s] = 1;
  while (q.size()) {
    int u = q.front();
    q.pop();
    queued[u] = 0;
    for (int v = 0; v < n; ++v) {
      if (u == v || dist[v] <= dist[u] + adj[u][v]) continue;
      dist[v] = dist[u] + adj[u][v];
      if (!queued[v]) {
        queued[v] = 1;
        q.emplace(v);
      }
    }
  }
  cout << dist[t];
}
