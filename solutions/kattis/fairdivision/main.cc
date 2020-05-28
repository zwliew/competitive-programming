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

  int t;
  cin >> t;
  while (t--) {
    int p, n;
    cin >> p >> n;
    vii arr(n);
    for (int i = 0; i < n; ++i) {
      int x;
      cin >> x;
      arr[i] = {x, i};
    }
    sort(arr.begin(), arr.end(), [&](auto &l, auto &r) {
      if (l.first != r.first) return l.first < r.first;
      return l.second > r.second;
    });

    vi output(n);
    ld avg = (ld)p / n;
    int i;
    for (i = 0; i < n && arr[i].first < (int)ceil(avg); ++i) {
      int delta = min(arr[i].first, (int)ceil(avg));
      p -= delta;
      avg = (ld)p / (n - i - 1);
      output[arr[i].second] = delta;
    }

    for (int j = n - 1; j >= i; --j) {
      p -= (int)ceil(avg);
      output[arr[j].second] = (int)ceil(avg);
      avg = (ld)p / (j - i);
    }

    if (p) {
      cout << "IMPOSSIBLE\n";
      continue;
    }

    for (auto x : output) {
      cout << x << ' ';
    }
    cout << '\n';
  }
}
