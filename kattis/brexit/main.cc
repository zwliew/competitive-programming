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

  // Use a modified version of Kahn's algorithm.
  int c, p, x, l;
  cin >> c >> p >> x >> l;

  vector<unordered_set<int>> adj(c + 1);
  vi orig(c + 1);
  for (int i = 0; i < p; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].emplace(v);
    adj[v].emplace(u);
    orig[u]++;
    orig[v]++;
  }

  queue<int> q;
  q.emplace(l);
  while (q.size()) {
    int u = q.front();
    q.pop();

    if (u == x) {
      cout << "leave";
      return 0;
    }

    for (int v : adj[u]) {
      adj[v].erase(u);
      if (adj[v].size() * 2 <= orig[v]) {
        q.emplace(v);
      }
    }
  }

  cout << "stay";
}
