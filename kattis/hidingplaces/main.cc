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

  int n;
  cin >> n;
  while (n--) {
    char c;
    int sr;
    cin >> c >> sr;
    int sc = c - 'a';
    sr = 8 - sr;
    queue<ii> q;
    q.emplace(sr, sc);
    vector<vi> dist(8, vi(8, 1e9));
    dist[sr][sc] = 0;
    int curmax = 0;
    while (q.size()) {
      auto [r, c] = q.front();
      q.pop();

      curmax = max(curmax, dist[r][c]);

      for (int dr = -2; dr <= 2; ++dr) {
        for (int dc = -2; dc <= 2; ++dc) {
          if (dr * dr + dc * dc != 5) continue;
          int nr = r + dr;
          int nc = c + dc;
          if (nr < 0 || nc < 0 || nr >= 8 || nc >= 8 ||
              dist[r][c] + 1 >= dist[nr][nc])
            continue;
          dist[nr][nc] = dist[r][c] + 1;
          q.emplace(nr, nc);
        }
      }
    }

    cout << curmax << ' ';
    for (int i = 0; i < 8; ++i) {
      for (int j = 0; j < 8; ++j) {
        if (dist[i][j] == curmax) {
          cout << (char)(j + 'a') << (char)(7 - i + '1') << ' ';
        }
      }
    }
    cout << '\n';
  }
}
