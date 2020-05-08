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
  for (int ti = 1; ti <= t; ++ti) {
    int n, o, e;
    cin >> n >> o >> e;

    vector<vi> capacity(n + 1);
    vi ppl(n + 1);
    for (int i = 0; i < e; ++i) {
      int h, p;
      cin >> h >> p;
      if (p) capacity[h].emplace_back(p);
      ppl[h]++;
    }

    vi ans(n + 1);
    bool ok = 1;
    for (int i = 1; i <= n && ok; ++i) {
      if (i == o) continue;
      sort(capacity[i].rbegin(), capacity[i].rend());
      int cur = 0;
      int j = 0;
      while (j < capacity[i].size() && cur < ppl[i]) {
        cur += capacity[i][j];
        ++j;
      }
      if (cur >= ppl[i]) {
        ans[i] = j;
      } else {
        ok = 0;
      }
    }

    cout << "Case #" << ti << ": ";
    if (ok) {
      for (int i = 1; i <= n; ++i) {
        cout << ans[i] << ' ';
      }
    } else {
      cout << "IMPOSSIBLE";
    }
    cout << '\n';
  }
}
