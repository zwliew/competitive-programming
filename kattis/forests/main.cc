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

int find(vi &p, int a) { return (p[a] == a ? a : (p[a] = find(p, p[a]))); }
void join(vi &p, int a, int b) {
  a = find(p, a);
  b = find(p, b);
  if (a == b) return;
  p[b] = a;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  // Implementation using disjoint sets
  // int p, t;
  // cin >> p >> t;
  // vi parent(p + 1);
  // iota(parent.begin(), parent.end(), 0);
  // vector<unordered_set<int>> seen(p + 1);
  // int x, y;
  // while (cin >> x >> y) {
  //   seen[x].emplace(y);
  // }

  // for (int i = 1; i <= p; ++i) {
  //   for (int j = i + 1; j <= p; ++j) {
  //     if (seen[i] == seen[j]) {
  //       join(parent, i, j);
  //     }
  //   }
  // }

  // vb visited(p + 1);
  // int size = 0;
  // for (int i = 1; i <= p; ++i) {
  //   if (!visited[parent[i]]) {
  //     visited[parent[i]] = 1;
  //     size++;
  //   }
  // }
  // cout << size;

  // Alternative implementation using a BST
  int p, t;
  cin >> p >> t;
  vector<vi> seen(p + 1);
  int x, y;
  while (cin >> x >> y) {
    seen[x].emplace_back(y);
  }

  set<vi> distinct;
  for (int i = 1; i <= p; ++i) {
    sort(seen[i].begin(), seen[i].end());
    distinct.emplace(seen[i]);
  }
  cout << distinct.size();
}
