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

  int n;
  cin >> n;
  vector<ii> pos(100001, {-1, 0});
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    if (pos[x].first == -1) {
      pos[x].first = i;
    } else if (pos[x].second == 0) {
      pos[x].second = i - pos[x].first;
      pos[x].first = i;
    } else if (i - pos[x].first == pos[x].second) {
      pos[x].first = i;
    } else {
      pos[x].first = 1e9;
      pos[x].second = 1e9;
    }
  }

  int cnt = 0;
  for (int i = 1; i <= 1e5; ++i) {
    if (pos[i].first != -1 && pos[i].first != 1e9) {
      ++cnt;
    }
  }

  cout << cnt << '\n';
  for (int i = 1; i <= 1e5; ++i) {
    if (pos[i].first != -1 && pos[i].first != 1e9) {
      cout << i << ' ' << pos[i].second << '\n';
    }
  }
}
