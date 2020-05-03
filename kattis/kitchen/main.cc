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

  // State space search with Dijkstra's algorithm.
  // Interesting state: vector of ints. Need to use a BST instead of a vector or
  // hashtable to store distances.
  int n, v;
  cin >> n;
  vi vol(n), s(n);
  for (int &x : vol) cin >> x;
  cin >> v;

  s[0] = vol[0];
  map<vi, int> dist;
  dist[s] = 0;
  priority_queue<pair<int, vi>, vector<pair<int, vi>>, greater<pair<int, vi>>>
      q;
  q.emplace(0, s);
  while (q.size()) {
    auto [d, u] = q.top();

    if (u[0] == v) {
      cout << d;
      return 0;
    }

    q.pop();
    if (dist.count(u) && d > dist[u]) continue;

    for (int i = 0; i < n; ++i) {
      if (!u[i]) continue;
      for (int j = 0; j < n; ++j) {
        if (i == j || vol[j] == u[j]) continue;
        int diff = min(vol[j] - u[j], u[i]);
        vi next = u;
        next[i] -= diff;
        next[j] += diff;
        if (!dist.count(next) || dist[next] > d + diff) {
          dist[next] = d + diff;
          q.emplace(d + diff, next);
        }
      }
    }
  }

  cout << "impossible";
}
