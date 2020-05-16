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
using vll = vector<ll>;

int rows, cols, mi, ma;
int ans(vector<vector<vi>> &dp, vi &blacks, int idx, int columns, bool black) {
  if (idx >= cols) {
    return (columns >= mi ? 0 : 1e9);
  }
  if (columns > ma) {
    return 1e9;
  }

  if (dp[idx][columns][black] != -1) {
    return dp[idx][columns][black];
  }

  dp[idx][columns][black] = ans(dp, blacks, idx + 1, columns + 1, black);
  if (black) {
    dp[idx][columns][black] += rows - blacks[idx];
  } else {
    dp[idx][columns][black] += blacks[idx];
  }
  if (columns >= mi) {
    int next = ans(dp, blacks, idx + 1, 1, !black);
    if (black) {
      next += blacks[idx];
    } else {
      next += rows - blacks[idx];
    }
    dp[idx][columns][black] = min(dp[idx][columns][black], next);
  }
  return dp[idx][columns][black];
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(9);

#ifdef LOCAL
  freopen("./input.txt", "r", stdin);
  freopen("./output.txt", "w", stdout);
#endif

  cin >> rows >> cols >> mi >> ma;

  vector<vc> grid(rows, vc(cols));
  vi blacks(cols);
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      cin >> grid[i][j];
      if (grid[i][j] == '#') {
        blacks[j]++;
      }
    }
  }

  vector<vector<vi>> dp(cols, vector<vi>(ma + 1, vi(2, -1)));
  cout << min(ans(dp, blacks, 0, 0, 1), ans(dp, blacks, 0, 0, 0));
}
