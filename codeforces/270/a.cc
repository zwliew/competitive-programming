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

  // int t;
  // cin >> t;
  // while (t--) {
  //   int a;
  //   cin >> a;
  //   bool found = 0;
  //   for (int i = 3;; ++i) {
  //     int total = (i - 2) * 180;
  //     if (total % i) continue;
  //     int div = total / i;
  //     if (div == a) {
  //       found = 1;
  //       break;
  //     }
  //     if (div > a) break;
  //   }
  //   if (found)
  //     cout << "YES\n";
  //   else
  //     cout << "NO\n";
  // }

  // Alternative O(1) solution
  // Sum of internal angles in a n-sided convex polygon == (n - 2) * 180
  // Hence, sum of supplementary angles == n * 180 - (n - 2) * 180 == 360
  // Hence, n * (180 - a) == 360
  // Hence, there is a solution only if 360 === 0 mod (180 - a).
  int t;
  cin >> t;
  while (t--) {
    int a;
    cin >> a;
    if (360 % (180 - a))
      cout << "NO\n";
    else
      cout << "YES\n";
  }
}
