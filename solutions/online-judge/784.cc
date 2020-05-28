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

const vii edges = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
void floodfill(vector<vc> &grid, int r, int c) {
  grid[r][c] = '#';
  for (auto &[dr, dc] : edges) {
    int nr = r + dr;
    int nc = c + dc;
    if (nr < 0 || nc < 0 || nr >= (int)grid.size() ||
        nc >= (int)grid[nr].size() || grid[nr][nc] != ' ')
      continue;
    floodfill(grid, nr, nc);
  }
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(9);

#ifdef LOCAL
  freopen("test.in", "r", stdin);
  freopen("test.out", "w", stdout);
#else
#endif

  int t;
  cin >> t;
  string s;
  getline(cin, s);
  while (t--) {
    vector<string> in;
    int maxlen = 0;
    while (getline(cin, s)) {
      bool end = true;
      for (char c : s) {
        if (c != '_') {
          end = false;
          break;
        }
      }
      if (end) break;

      in.eb(s);
      maxlen = max(maxlen, (int)s.size());
    }

    int sr, sc;
    vector<vc> grid(in.size(), vc(maxlen));
    for (int i = 0; i < (int)in.size(); ++i) {
      for (int j = 0; j < (int)in[i].size(); ++j) {
        grid[i][j] = in[i][j];
        if (grid[i][j] == '*') {
          sr = i;
          sc = j;
        }
      }
    }

    floodfill(grid, sr, sc);

    for (auto &x : grid) {
      for (auto &c : x) {
        if (c) cout << c;
      }
      cout << '\n';
    }
    cout << s << '\n';
  }
}
