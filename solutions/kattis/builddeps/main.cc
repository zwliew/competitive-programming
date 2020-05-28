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

void topoSort(vector<string> &order, unordered_map<string, vector<string>> &adj,
              unordered_set<string> &vis, string s) {
  if (vis.count(s)) return;
  vis.emplace(s);
  for (auto v : adj[s]) {
    topoSort(order, adj, vis, v);
  }
  order.emplace_back(s);
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  // Build dependencies directed acyclic graph. Topological sort then DFS.
  unordered_map<string, vector<string>> adj;
  int n;
  cin >> n;
  string line;
  getline(cin, line);
  while (n--) {
    getline(cin, line);
    istringstream iss(line);
    vector<string> tokens{istream_iterator<string>(iss),
                          istream_iterator<string>()};
    tokens.front().pop_back();
    for (int i = 1; i < tokens.size(); ++i) {
      adj[tokens[i]].emplace_back(tokens.front());
    }
  }

  string s;
  cin >> s;
  vector<string> order;
  unordered_set<string> vis;
  topoSort(order, adj, vis, s);
  reverse(order.begin(), order.end());

  for (string x : order) {
    cout << x << '\n';
  }
}
