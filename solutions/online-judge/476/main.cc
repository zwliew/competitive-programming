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

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(9);

#ifndef ONLINE_JUDGE
  freopen("./input.txt", "r", stdin);
  freopen("./output.txt", "w", stdout);
#endif

  char c;
  vector<tuple<ld, ld, ld, ld>> rects;
  while (cin >> c && c == 'r') {
    ld x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    rects.emplace_back(x1, y1, x2, y2);
  }

  ld x, y;
  int pointnum = 1;
  while (cin >> x >> y) {
    if (fabsl(x - 9999.9) < 1e-9 && fabsl(y - 9999.9) < 1e-9) break;
    bool found = 0;
    for (int i = 0; i < rects.size(); ++i) {
      auto &[x1, y1, x2, y2] = rects[i];
      if (x > x1 && x < x2 && y > y2 && y < y1) {
        found = 1;
        cout << "Point " << pointnum << " is contained in figure " << i + 1
             << '\n';
      }
    }
    if (!found) {
      cout << "Point " << pointnum << " is not contained in any figure\n";
    }
    ++pointnum;
  }
}
