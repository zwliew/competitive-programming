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

bool dfs(vector<vi> &adj, vi &colors, int u, int color) {
  colors[u] = color;
  for (int v : adj[u]) {
    if (!colors[v]) {
      if (dfs(adj, colors, v, colors[u] == 1 ? 2 : 1)) {
        return 1;
      }
    } else if (colors[v] == colors[u]) {
      return 1;
    }
  }
  return 0;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  // Bipartite graph check
  int n;
  cin >> n;
  unordered_map<string, int> mp;
  vector<string> mps;
  for (int i = 0; i < n; ++i) {
    string x;
    cin >> x;
    mp[x] = i;
    mps.emplace_back(x);
  }

  int m;
  cin >> m;
  vector<vi> adj(n);
  for (int i = 0; i < m; ++i) {
    string u, v;
    cin >> u >> v;
    adj[mp[u]].emplace_back(mp[v]);
    adj[mp[v]].emplace_back(mp[u]);
  }

  vi colors(n);
  for (int u = 0; u < n; ++u) {
    if (!colors[u]) {
      if (dfs(adj, colors, u, 1)) {
        cout << "impossible";
        return 0;
      }
    }
  }

  for (int i = 0; i < n; ++i) {
    if (colors[i] == 1) {
      cout << mps[i] << ' ';
    }
  }

  cout << '\n';
  for (int i = 0; i < n; ++i) {
    if (colors[i] == 2) {
      cout << mps[i] << ' ';
    }
  }
}
