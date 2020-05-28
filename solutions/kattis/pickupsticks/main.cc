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

bool checkCycle(vi &vis, vector<vi> &adj, int u) {
  vis[u] = 2;
  for (int v : adj[u]) {
    if (vis[v] == 2) return 1;
    if (!vis[v] && checkCycle(vis, adj, v)) return 1;
  }
  vis[u] = 1;
  return 0;
}

void topoSort(vi &order, vb &vis, vector<vi> &adj, int u) {
  vis[u] = 1;
  for (int v : adj[u]) {
    if (vis[v]) continue;
    topoSort(order, vis, adj, v);
  }
  order.push_back(u);
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  // Check if it's a DAG by finding cycles, then topological sort.
  int n, m;
  cin >> n >> m;
  vector<vi> adj(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    adj[u].emplace_back(v);
  }

  vi visState(n);
  for (int u = 0; u < n; ++u) {
    if (visState[u] == 0) {
      if (checkCycle(visState, adj, u)) {
        cout << "IMPOSSIBLE";
        return 0;
      }
    }
  }

  vb visited(n);
  vi order;
  for (int u = 0; u < n; ++u) {
    if (visited[u]) continue;
    topoSort(order, visited, adj, u);
  }

  for (int i = order.size() - 1; i >= 0; --i) {
    cout << order[i] + 1 << '\n';
  }
}
