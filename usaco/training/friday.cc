/*
ID: zhaowei10
TASK: friday
LANG: C++14
*/
#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdio>
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
string to_string(char c) { return string(1, c); }
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
  freopen("friday.in", "r", stdin);
  freopen("friday.out", "w", stdout);
#endif

  int n;
  cin >> n;
  int day = 2;
  int date = 1;
  int month = 1;
  int year = 1900;
  vi freqs(7);
  while (date != 31 || month != 12 || year != 1900 + n - 1) {
    if (date == 13) {
      freqs[day]++;
    }

    date++;
    bool newMonth = false;
    if (month == 4 || month == 6 || month == 9 || month == 11) {
      if (date == 31) newMonth = true;
    } else if (month == 2) {
      if (year % 400 == 0 || (year % 4 == 0 && year % 100)) {
        if (date == 30) newMonth = true;
      } else {
        if (date == 29) newMonth = true;
      }
    } else if (date == 32) {
      newMonth = true;
    }

    if (newMonth) {
      date = 1;
      month++;
    }

    if (month == 13) {
      month = 1;
      ++year;
    }

    day = (day + 1) % 7;
  }

  cout << freqs.front();
  for (int i = 1; i < 7; ++i) {
    cout << " " << freqs[i];
  }
  cout << '\n';
}
