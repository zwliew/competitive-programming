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

string to_string(char c) { return string(1, c); }
string to_string(string s) { return '"' + s + '"'; }
string to_string(const char *s) { return to_string((string)s); }
string to_string(bool b) { return (b ? "true" : "false"); }
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> t) {
  auto &[a, b, c] = t;
  return "(" + to_string(a) + ", " + to_string(b) + ", " + to_string(c) + ")";
}
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> t) {
  auto &[a, b, c, d] = t;
  return "(" + to_string(a) + ", " + to_string(b) + ", " + to_string(c) + ", " +
         to_string(d) + ")";
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

int findSet(vi &p, int a) { return p[a] == a ? a : p[a] = findSet(p, p[a]); }
void unionSet(vi &p, vi &r, int a, int b) {
  a = findSet(p, a);
  b = findSet(p, b);
  if (a == b) return;
  if (r[a] < r[b])
    swap(a, b);
  else if (r[a] == r[b])
    ++r[a];
  p[b] = a;
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
    int s, p;
    cin >> s >> p;
    vii vertices;
    for (int i = 0; i < p; ++i) {
      int x, y;
      cin >> x >> y;
      vertices.eb(x, y);
    }

    vector<tuple<ll, int, int>> edges;
    for (int i = 0; i < p; ++i) {
      for (int j = i + 1; j < p; ++j) {
        int dx = vertices[i].first - vertices[j].first;
        int dy = vertices[i].second - vertices[j].second;
        ll dist = (ll)dx * dx + dy * dy;
        edges.eb(dist, i, j);
      }
    }
    sort(edges.begin(), edges.end());

    int remaining = p - s;
    vi pa(p), r(p);
    iota(pa.begin(), pa.end(), 0);
    ld cost = 0;
    for (int i = 0; i < (int)edges.size() && remaining; ++i) {
      auto &[w, u, v] = edges[i];
      if (findSet(pa, u) != findSet(pa, v)) {
        unionSet(pa, r, u, v);
        cost = max(cost, sqrtl(w));
        --remaining;
      }
    }

    cout << setprecision(2) << cost << '\n';
  }
}
