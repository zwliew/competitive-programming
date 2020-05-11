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

  ll l, r;
  cin >> l >> r;

  // Brute force. Time complexity: O(n^3logA)
  // for (ll a = l; a <= r; ++a) {
  //   for (ll b = a + 1; b <= r; ++b) {
  //     for (ll c = b + 1; c <= r; ++c) {
  //       if (gcd(a, b) == 1 && gcd(b, c) == 1 && gcd(a, c) > 1) {
  //         cout << a << ' ' << b << ' ' << c;
  //         return 0;
  //       }
  //     }
  //   }
  // }
  // cout << -1;

  // Alternative O(1) method. Use the fact that every 2 consecutive numbers are
  // coprime. And, if the first number is even, the third number has to be prime
  // with the first number.
  // Hence, just output an even number x, followed by (x + 1), and (x + 2).
  if (l % 2) ++l;
  if (r - l < 2) {
    cout << -1;
  } else {
    cout << l << ' ' << l + 1 << ' ' << l + 2;
  }
}
