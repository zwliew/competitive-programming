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

  int a, b;
  cin >> a >> b;

  // Editorial number theory solution
  vi factors = {2, 3, 5};
  int ans = 0;
  for (int i = 0; i < (int)factors.size(); ++i) {
    int cnt = 0;
    while (a % factors[i] == 0) {
      ++cnt;
      a /= factors[i];
    }

    while(b % factors[i] == 0) {
      --cnt;
      b /= factors[i];
    }

    ans += abs(cnt);
  }

  if (a != b) {
    cout << -1;
    return 0;
  }

  cout << ans;

  // My original BFS solution
  // map<ii, int> dist;
  // auto sp = make_pair(min(a, b), max(a, b));
  // dist[sp] = 0;
  // queue<ii> q;
  // q.emplace(sp);
  // while (q.size()) {
  //   auto [x, y] = q.front();
  //   q.pop();

  //   if (x == y) {
  //     cout << dist[{x, y}];
  //     return 0;
  //   }

  //   int ndist = dist[{x, y}] + 1;
  //   if (y % 5 == 0) {
  //     auto p = make_pair(min(x, y / 5), max(x, y / 5));
  //     if (!dist.count(p)) {
  //       dist[p] = ndist;
  //       q.emplace(p);
  //     }
  //   }

  //   if (y % 3 == 0) {
  //     auto p = make_pair(min(x, y / 3), max(x, y / 3));
  //     if (!dist.count(p)) {
  //       dist[p] = ndist;
  //       q.emplace(p);
  //     }
  //   }

  //   if (y % 2 == 0) {
  //     auto p = make_pair(min(x, y / 2), max(x, y / 2));
  //     if (!dist.count(p)) {
  //       dist[p] = ndist;
  //       q.emplace(p);
  //     }
  //   }
  // }

  // cout << -1;
}
