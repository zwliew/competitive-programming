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

int find(vi &p, int a) { return p[a] == a ? a : (p[a] = find(p, p[a])); }
void join(vi &p, vi &sz, vi &rank, int a, int b) {
  a = find(p, a);
  b = find(p, b);
  if (a == b) return;
  if (rank[a] < rank[b]) {
    swap(a, b);
  }
  p[b] = a;
  if (rank[a] == rank[b]) ++rank[a];
  sz[a] += sz[b];
}
int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int n, q;
  cin >> n >> q;
  vi p(n + 1), sz(n + 1, 1), rank(n + 1);
  iota(p.begin(), p.end(), 0);
  while (q--) {
    char x;
    int a, b;
    cin >> x >> a;
    if (x == 't') {
      cin >> b;
      join(p, sz, rank, a, b);
    } else {
      cout << sz[find(p, a)] << '\n';
    }
  }
}
