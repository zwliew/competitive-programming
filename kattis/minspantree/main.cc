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

int find(vi &p, int a) { return p[a] == a ? a : p[a] = find(p, p[a]); }
void join(vi &p, vi &r, int a, int b) {
  a = find(p, a);
  b = find(p, b);
  if (a == b) return;
  if (r[a] < r[b])
    swap(a, b);
  else if (r[a] == r[b])
    r[a]++;
  p[b] = a;
}
int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(9);

  int n, m;
  while (cin >> n >> m && (n || m)) {
    vi p(n), r(n);
    iota(p.begin(), p.end(), 0);

    vector<tuple<int, int, int>> edges;
    for (int i = 0; i < m; ++i) {
      int u, v, w;
      cin >> u >> v >> w;
      if (u > v) swap(u, v);
      edges.emplace_back(w, u, v);
    }
    sort(edges.begin(), edges.end());

    int cnt = 0, cost = 0;
    vii mst;
    for (int i = 0; i < edges.size() && cnt < n - 1; ++i) {
      auto &[w, u, v] = edges[i];
      if (find(p, u) == find(p, v)) continue;
      join(p, r, u, v);
      cnt++;
      cost += w;
      mst.emplace_back(u, v);
    }

    if (cnt < n - 1) {
      cout << "Impossible\n";
      continue;
    }

    sort(mst.begin(), mst.end());
    cout << cost << '\n';
    for (auto &[u, v] : mst) {
      cout << u << ' ' << v << '\n';
    }
  }
}
