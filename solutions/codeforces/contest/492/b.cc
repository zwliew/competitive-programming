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

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(9);

#ifndef ONLINE_JUDGE
  freopen("./input.txt", "r", stdin);
  freopen("./output.txt", "w", stdout);
#endif

  int n, l;
  cin >> n >> l;
  vi arr(n);
  for (auto &x : arr) cin >> x;
  sort(arr.begin(), arr.end());

  ld ans = max(l - arr.back(), arr.front());
  for (int i = 1; i < n; ++i) {
    ans = max(ans, (ld)(arr[i] - arr[i - 1]) / 2);
  }

  cout << ans;

  // Alternative binary search solution.
  // int n, l;
  // cin >> n >> l;
  // vi arr(n);
  // for (auto &x : arr) cin >> x;
  // sort(arr.begin(), arr.end());

  // ld lo = 1, hi = l;
  // ld ans = l;
  // for (int i = 0; i < 100; ++i) {
  //   ld mid = lo + (hi - lo) / 2;
  //   bool ok = 1;
  //   ld prev = 0;
  //   for (int i = 0; i < n; ++i) {
  //     if (arr[i] - mid > prev) {
  //       ok = 0;
  //       break;
  //     }
  //     prev = max(prev, arr[i] + mid);
  //   }
  //   ok = ok && prev >= l;

  //   if (ok) {
  //     ans = mid;
  //     hi = mid - 1;
  //   } else {
  //     lo = mid + 1;
  //   }
  // }

  // cout << ans;
}
