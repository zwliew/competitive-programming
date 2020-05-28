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

#ifndef ONLINE_JUDGE
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

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(9);

#ifndef ONLINE_JUDGE
  freopen("./input.txt", "r", stdin);
  freopen("./output.txt", "w", stdout);
#endif

  int x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  if (x1 > x2) swap(x1, x2);
  if (y1 > y2) swap(y1, y2);

  set<ii> warm;
  int n;
  cin >> n;
  while (n--) {
    ll x, y, r;
    cin >> x >> y >> r;
    for (int i = x1; i <= x2; ++i) {
      ll dist = (i - x) * (i - x) + (y1 - y) * (y1 - y);
      if (dist <= r * r) {
        warm.emplace(i, y1);
      }
      dist = (i - x) * (i - x) + (y2 - y) * (y2 - y);
      if (dist <= r * r) {
        warm.emplace(i, y2);
      }
    }
    for (int i = y1; i <= y2; ++i) {
      ll dist = (x1 - x) * (x1 - x) + (i - y) * (i - y);
      if (dist <= r * r) {
        warm.emplace(x1, i);
      }
      dist = (x2 - x) * (x2 - x) + (i - y) * (i - y);
      if (dist <= r * r) {
        warm.emplace(x2, i);
      }
    }
  }

  int ans = 0;
  for (int i = x1; i <= x2; ++i) {
    if (!warm.count({i, y1})) {
      ++ans;
    }
    if (!warm.count({i, y2})) {
      ++ans;
    }
  }
  for (int i = y1; i <= y2; ++i) {
    if (!warm.count({x1, i})) {
      ++ans;
    }
    if (!warm.count({x2, i})) {
      ++ans;
    }
  }

  if (!warm.count({x1, y1})) --ans;
  if (!warm.count({x1, y2})) --ans;
  if (!warm.count({x2, y1})) --ans;
  if (!warm.count({x2, y2})) --ans;

  cout << ans;
}
