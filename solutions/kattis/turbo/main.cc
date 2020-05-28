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

  // Same idea as moviecollection. Dynamic RSQ. Allocate enough space for all
  // the "moves of elements" and use range sum queries to query the number of
  // items to move an element across;
  int n;
  cin >> n;

  vi t(n * 3 + 1);
  auto update = [&](int i, int x) {
    for (++i; i <= n * 3; i += i & -i) {
      t[i] += x;
    }
  };
  auto query = [&](int i) {
    int res = 0;
    for (++i; i; i -= i & -i) {
      res += t[i];
    }
    return res;
  };

  vi mp(n + 1);
  for (int i = n; i < n * 2; ++i) {
    int x;
    cin >> x;
    update(i, 1);
    mp[x] = i;
  }

  int start = 1;
  int end = n;
  int startIdx = 0;
  int endIdx = n * 3 - 1;
  for (int i = 1; i <= n; ++i) {
    if (i % 2) {
      cout << query(mp[start] - 1) - query(startIdx) << '\n';
      update(mp[start], -1);
      update(startIdx, 1);
      mp[start] = startIdx;
      ++startIdx;
      ++start;
    } else {
      cout << query(endIdx) - query(mp[end]) << '\n';
      update(mp[end], -1);
      update(endIdx, 1);
      mp[end] = endIdx;
      --endIdx;
      --end;
    }
  }
}
