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
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

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
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> t) {
  return "(" + to_string(get<0>(t)) + ", " + to_string(get<1>(t)) + ", " +
         to_string(get<2>(t)) + ")";
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
using vll = vector<ll>;

int findSet(vi &p, int u) { return p[u] == u ? u : p[u] = findSet(p, p[u]); }

void unionSet(vi &p, vi &r, int u, int v) {
  u = findSet(p, u);
  v = findSet(p, v);
  if (u == v) return;
  if (r[u] < r[v])
    swap(u, v);
  else if (r[u] == r[v])
    ++r[u];
  p[v] = u;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(9);

#ifdef LOCAL
  freopen("./input.txt", "r", stdin);
  freopen("./output.txt", "w", stdout);
#endif

  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<tuple<int, int, int, int>> edges;
    for (int i = 0; i < m; ++i) {
      int u, v, w;
      cin >> u >> v >> w;
      --u, --v;
      edges.eb(w, u, v, i);
    }
    sort(edges.begin(), edges.end());

    vi p(n), r(n);
    iota(p.begin(), p.end(), 0);
    int cost = 0;
    int remaining = n - 1;
    vi mst;
    for (int i = 0; i < m && remaining; ++i) {
      auto &[w, u, v, j] = edges[i];
      if (findSet(p, u) != findSet(p, v)) {
        unionSet(p, r, u, v);
        mst.eb(j);
        cost += w;
        --remaining;
      }
    }

    vb blocked(m);
    int cost2 = INT_MAX;
    for (int b : mst) {
      blocked[b] = true;

      iota(p.begin(), p.end(), 0);
      fill(r.begin(), r.end(), 0);
      int curCost = 0;
      remaining = n - 1;
      for (int i = 0; i < m && remaining; ++i) {
        auto &[w, u, v, j] = edges[i];
        if (!blocked[j] && findSet(p, u) != findSet(p, v)) {
          unionSet(p, r, u, v);
          curCost += w;
          --remaining;
        }
      }

      if (!remaining) cost2 = min(cost2, curCost);

      blocked[b] = false;
    }

    cout << cost << ' ' << cost2 << '\n';
  }
}
