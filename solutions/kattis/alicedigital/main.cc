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

  // Sliding window problem.
  // Use a monoqueue (monotonically increasing queue) to track the min element.
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;

    vi arr(n);
    for (auto &x : arr) cin >> x;

    deque<pair<ll, ll>> monoq;
    auto emplace = [&](ll val) {
      ll count = 1;
      while (monoq.size() && monoq.back().first >= val) {
        count += monoq.back().second;
        monoq.pop_back();
      }
      monoq.emplace_back(val, count);
    };
    auto pop = [&]() {
      monoq.front().second--;
      if (monoq.front().second == 0) {
        monoq.pop_front();
      }
    };

    ll mcount = 0;
    ll best = 0;
    ll j = 0, cursum = 0;
    for (int i = 0; i < n; ++i) {
      emplace(arr[i]);
      cursum += arr[i];
      if (arr[i] == m) ++mcount;
      while (j <= i && (mcount > 1 || monoq.front().first < m)) {
        pop();
        if (arr[j] == m) {
          --mcount;
        }
        cursum -= arr[j];
        ++j;
      }
      if (mcount == 1 && monoq.front().first == m) {
        best = max(best, cursum);
      }
    }

    cout << best << '\n';
  }
}
