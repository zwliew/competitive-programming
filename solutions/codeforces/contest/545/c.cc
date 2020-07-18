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

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(9);

#ifdef LOCAL
  freopen("./input.txt", "r", stdin);
  freopen("./output.txt", "w", stdout);
#endif

  int n;
  cin >> n;
  vii arr(n + 2);
  arr[0] = {INT_MIN, 0};
  for (int i = 1; i <= n; ++i) {
    int x, h;
    cin >> x >> h;
    arr[i] = {x, h};
  }
  arr[n + 1] = {INT_MAX, 0};

  int ans = 0;
  vector<vi> dp(n + 2,
                vi(3));  // 0 =dont fell, 1=fell to right, 2= fell to left

  for (int i = n; i; --i) {
    dp[i][0] = max({dp[i + 1][2], dp[i + 1][0], dp[i + 1][1]});

    if (arr[i].first - arr[i].second > arr[i - 1].first) {
      dp[i][2] = max({dp[i + 1][0], dp[i + 1][1], dp[i + 1][2]}) + 1;
    } else {
      dp[i][2] = INT_MIN;
    }

    if (arr[i].first + arr[i].second < arr[i + 1].first) {
      dp[i][1] = max(dp[i + 1][0], dp[i + 1][1]);
      if (arr[i].first + arr[i].second < arr[i + 1].first - arr[i + 1].second) {
        dp[i][1] = max(dp[i][1], dp[i + 1][2]);
      }
      ++dp[i][1];
    } else {
      dp[i][1] = INT_MIN;
    }

    ans = max({ans, dp[i][0], dp[i][1], dp[i][2]});
  }
  debug(dp);
  cout << ans;
}
