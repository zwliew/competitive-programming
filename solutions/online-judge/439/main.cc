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
using vll = vector<ll>;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(9);

#ifndef ONLINE_JUDGE
  freopen("./input.txt", "r", stdin);
  freopen("./output.txt", "w", stdout);
#endif

  const vii edges = {
      {1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {-2, 1}, {2, -1}, {-2, -1},
  };
  vector<vector<vector<vi>>> dist(
      8, vector<vector<vi>>(8, vector<vi>(8, vi(8, 1e9))));
  for (int i = 0; i < 8; ++i)
    for (int j = 0; j < 8; ++j) dist[i][j][i][j] = 0;
  string s, d;
  while (cin >> s >> d) {
    int sr = s.front() - 'a';
    int sc = s.back() - '0' - 1;
    int dr = d.front() - 'a';
    int dc = d.back() - '0' - 1;

    if (dist[sr][sc][dr][dc] < 1e9) {
      cout << "To get from " << s << " to " << d << " takes "
           << dist[sr][sc][dr][dc] << " knight moves.\n";
      continue;
    }

    queue<ii> q;
    q.emplace(sr, sc);
    while (q.size()) {
      auto [r, c] = q.front();
      q.pop();

      if (r == dr && c == dc) {
        cout << "To get from " << s << " to " << d << " takes "
             << dist[sr][sc][dr][dc] << " knight moves.\n";
        break;
      }

      for (auto &[der, dec] : edges) {
        int nr = r + der;
        int nc = c + dec;
        if (nr < 0 || nc < 0 || nr >= 8 || nc >= 8) continue;
        if (dist[sr][sc][nr][nc] < 1e9) continue;
        dist[sr][sc][nr][nc] = dist[sr][sc][r][c] + 1;
        q.emplace(nr, nc);
      }
    }
  }
}
