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

  // State space search with Dijkstra's algorithm, where the state is
  // (intersection, hasBeenThroughGAndH)
  int tests;
  cin >> tests;
  while (tests--) {
    int n, m, t, s, g, h;
    cin >> n >> m >> t >> s >> g >> h;
    --s, --g, --h;

    vector<vii> adj(n);
    for (int i = 0; i < m; ++i) {
      int u, v, w;
      cin >> u >> v >> w;
      --u, --v;
      adj[u].emplace_back(v, w);
      adj[v].emplace_back(u, w);
    }

    vi dest(t);
    for (int &x : dest) {
      cin >> x;
      --x;
    }
    sort(dest.begin(), dest.end());

    vector<vi> dist(n, vi(2, 1e9));
    dist[s][0] = 0;
    priority_queue<tuple<int, int, bool>, vector<tuple<int, int, bool>>,
                   greater<tuple<int, int, bool>>>
        q;
    q.emplace(0, s, 0);
    while (q.size()) {
      auto [d, u, b] = q.top();
      q.pop();

      if (d > dist[u][b]) continue;
      for (auto &[v, w] : adj[u]) {
        int nd = d + w;
        bool nb = (u == g && v == h) || (v == g && u == h) || b;
        if (nd < dist[v][nb]) {
          dist[v][nb] = nd;
          q.emplace(nd, v, nb);
        }
      }
    }

    for (int v : dest) {
      debug(v, dist[v]);
      if (dist[v][1] < 1e9 && dist[v][1] <= dist[v][0]) {
        cout << v + 1 << ' ';
      }
    }
    cout << '\n';
  }
}
