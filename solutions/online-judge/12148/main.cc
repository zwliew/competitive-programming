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

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(9);

  int n;
  while (cin >> n && n) {
    int prev = -1e9, prevc = -1e9, prevy = -1e9;
    bool prevleap = false;
    int cnt = 0;
    ll sum = 0;
    for (int i = 0; i < n; ++i) {
      int d, m, y, c;
      cin >> d >> m >> y >> c;

      bool leap = ((y % 4 == 0) && (y % 100)) || (y % 400 == 0);
      int days = d;
      for (int j = 1; j < m; ++j) {
        if (j == 2) {
          days += 28 + leap;
        } else if (j == 4 || j == 6 || j == 9 || j == 11) {
          days += 30;
        } else {
          days += 31;
        }
      }

      if (y == prevy && days == prev + 1 ||
          (y == prevy + 1 && days == 1 && prev == 365 + prevleap)) {
        ++cnt;
        sum += c - prevc;
      }

      prevc = c;
      prev = days;
      prevy = y;
      prevleap = leap;
    }

    cout << cnt << ' ' << sum << '\n';
  }
}
