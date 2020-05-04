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

int find(vi &p, int a) {
  if (p[a] == a) return a;
  return p[a] = find(p, p[a]);
}
void join(vi &p, vi &rank, int a, int b) {
  a = find(p, a);
  b = find(p, b);
  if (a != b) {
    if (rank[a] < rank[b]) {
      swap(a, b);
    } else if (rank[a] == rank[b]) {
      ++rank[a];
    }
    p[b] = a;
  }
}
int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  // Classic MST. Solve with Kruskal's algorithm with union-find.
  int t;
  cin >> t;
  while (t--) {
    int m, c;
    cin >> m >> c;

    int minW = 1e9;
    vector<tuple<int, int, int>> edge;
    for (int i = 0; i * 2 < c * (c - 1); ++i) {
      int u, v, w;
      cin >> u >> v >> w;
      minW = min(minW, w);
      edge.emplace_back(w, u, v);
    }

    if (m < c + (c - 1) * minW) {
      cout << "no\n";
      continue;
    }

    sort(edge.begin(), edge.end());

    vi p(c), rank(c);
    iota(p.begin(), p.end(), 0);
    int count = 0, weight = 0;
    for (int i = 0; i < edge.size() && count < c; ++i) {
      auto &[w, u, v] = edge[i];
      if (find(p, u) != find(p, v)) {
        join(p, rank, u, v);
        weight += w;
        ++count;
      }
    }
    cout << (weight <= m - c ? "yes\n" : "no\n");
  }
}
