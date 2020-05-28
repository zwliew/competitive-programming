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

  int r, s, w;
  cin >> r >> s >> w;
  vector<vi> prefixSums(r + 1, vi(s + 1));
  vector<vb> grid(r, vb(s));
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < s; ++j) {
      char c;
      cin >> c;
      grid[i][j] = c == '*';
      prefixSums[i + 1][j + 1] = prefixSums[i][j + 1] + prefixSums[i + 1][j] -
                                 prefixSums[i][j] + (c == '*');
    }
  }

  int r1, r2, c1, c2, best = 0;
  for (int i = 1; i <= r - w + 1; ++i) {
    for (int j = 1; j <= s - w + 1; ++j) {
      int k = i + w - 1;
      int l = j + w - 1;
      int cur = prefixSums[k - 1][l - 1] - prefixSums[i][l - 1] -
                prefixSums[k - 1][j] + prefixSums[i][j];
      if (cur > best) {
        best = cur;
        r1 = i;
        r2 = k;
        c1 = j;
        c2 = l;
      }
    }
  }
  --r1, --r2, --c1, --c2;
  cout << best << '\n';
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < s; ++j) {
      if ((i == r1 || i == r2) && (j == c1 || j == c2)) {
        cout << '+';
      } else if ((i >= r1 && i <= r2) && (j == c1 || j == c2)) {
        cout << '|';
      } else if ((j >= c1 && j <= c2) && (i == r1 || i == r2)) {
        cout << '-';
      } else {
        cout << (grid[i][j] ? '*' : '.');
      }
    }
    cout << '\n';
  }
}
