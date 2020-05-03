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

int color(vi &areas, vector<vi> &adj, vb &vis, int u, bool col) {
  if (vis[u]) return 0;
  vis[u] = 1;
  int cost = areas[u] * col;
  for (int v : adj[u]) {
    cost += color(areas, adj, vis, v, !col);
  }
  return cost;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  // There are only 2 ways to color a bipartite graph. Try both ways and take
  // the one with the minimum cost.
  int n, e;
  cin >> n >> e;
  vi areas(n);
  for (int &x : areas) cin >> x;

  vector<vi> adj(n);
  for (int i = 0; i < e; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
  }

  vb visited(n);
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    vb copy = visited;
    int cost1 = color(areas, adj, visited, i, 1);
    visited = copy;
    int cost2 = color(areas, adj, visited, i, 0);
    ans += min(cost1, cost2);
  }

  cout << ans;
}
