/*
ID: zhaowei10
TASK:
LANG: C++14
*/
#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>

using namespace __gnu_cxx;
using namespace __gnu_pbds;
using namespace std;

#ifdef LOCAL
string to_string(char c) { return string(1, c); }
string to_string(string s) { return '"' + s + '"'; }
string to_string(const char *s) { return to_string((string)s); }
string to_string(bool b) { return (b ? "true" : "false"); }
string to_string(vector<bool> v) {
  string res = "{";
  for (int i = 0; i < (int)v.size(); ++i) {
    res += char('0' + v[i]);
  }
  res += "}";
  return res;
}
template <size_t N>
string to_string(bitset<N> b) {
  string res = "";
  for (int i = 0; i < N; ++i) {
    res += char('0' + b[i]);
  }
  return res;
}
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> t) {
  return "(" + to_string(get<0>(t)) + ", " + to_string(get<1>(t)) + ", " +
         to_string(get<2>(t)) + ")";
}
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> t) {
  return "(" + to_string(get<0>(t)) + ", " + to_string(get<1>(t)) + ", " +
         to_string(get<2>(t)) + ", " + to_string(get<3>(t)) + ")";
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
#define debug(...) cerr << '[' << #__VA_ARGS__ << "]:", _debug(__VA_ARGS__)
#else
#define debug(...) 0
#endif

#define eb emplace_back

using ll = long long;
using ld = long double;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;
using vc = vector<char>;
using vb = vector<bool>;
using vll = vector<ll>;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(9);

#ifdef LOCAL
  freopen("test.in", "r", stdin);
  freopen("test.out", "w", stdout);
#else
#endif

  // Sweep line algorithm (create entrance and exit events for each building)
  vector<tuple<int, int, bool>> events;
  int l, h, r;
  while (cin >> l >> h >> r) {
    events.eb(l, h, false);
    events.eb(r, h, true);
  }
  sort(events.begin(), events.end());

  int prev = 0;
  multiset<int> heights;
  bool first = true;
  for (int i = 0; i < (int)events.size(); ++i) {
    auto x = get<0>(events[i]);
    for (int j = i; j < (int)events.size() && get<0>(events[j]) == x;
         i = j, ++j) {
      auto &[_, ch, exit] = events[j];
      if (exit) {
        heights.erase(heights.find(ch));
      } else {
        heights.emplace(ch);
      }
    }

    auto it = heights.rbegin();
    int cur = (it == heights.rend() ? 0 : *it);
    if (cur != prev) {
      if (first) {
        first = false;
      } else {
        cout << ' ';
      }
      cout << x << ' ' << cur;
      prev = cur;
    }
  }
  cout << '\n';

  // Brute force solution (create a height map over 10K x-coordinates)
  // vi maxheights(10000);
  // int l, h, r;
  // while (cin >> l >> h >> r) {
  //   for (int x = l; x < r; ++x) {
  //     maxheights[x] = max(maxheights[x], h);
  //   }
  // }

  // int prev = 0;
  // for (int x = 0; x < 10000; ++x) {
  //   if (maxheights[x] != prev) {
  //     if (first)
  //       first = false;
  //     else
  //       cout << ' ';
  //     cout << x << ' ' << maxheights[x];
  //     prev = maxheights[x];
  //   }
  // }
  // cout << '\n';
}
