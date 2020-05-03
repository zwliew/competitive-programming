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

#define LOCAL
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

  // State-space search on a weighted, undirected graph. Use Dijkstra's
  // algorithm with state parameters (location, colors covered).
  int n, m;
  cin >> n >> m;
  unordered_map<char, int> colorMap = {{'R', 1},  {'O', 2},  {'Y', 4}, {'G', 8},
                                       {'B', 16}, {'I', 32}, {'V', 64}};
  vector<vector<tuple<int, int, int>>> adj(n);
  for (int i = 0; i < m; ++i) {
    int u, v, w;
    char c;
    cin >> u >> v >> w >> c;
    --u, --v;
    adj[u].emplace_back(v, w, colorMap[c]);
    adj[v].emplace_back(u, w, colorMap[c]);
  }

  vector<vi> dist(n, vi(128, 1e9));
  dist[0][0] = 0;
  priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                 greater<tuple<int, int, int>>>
      q;
  q.emplace(0, 0, 0);
  while (q.size()) {
    auto [d, u, c] = q.top();
    q.pop();
    if (c == 127 && u == 0) {
      cout << d;
      return 0;
    }
    if (d > dist[u][c]) continue;
    for (auto &[v, w, dc] : adj[u]) {
      int nd = d + w;
      int nc = c | dc;
      if (nd < dist[v][nc]) {
        dist[v][nc] = nd;
        q.emplace(nd, v, nc);
      }
    }
  }
}
