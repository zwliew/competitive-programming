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

  int h, b;
  cin >> h;
  vi hv(h);
  int maxh = 0;
  for (int &x : hv) {
    cin >> x;
    maxh += x;
  }
  cin >> b;
  vi bv(b);
  int maxb = 0;
  for (int &x : bv) {
    cin >> x;
    maxb += x;
  }

  vector<vi> dpb(b + 1, vi(maxb + 1, 1e9)), dph(h + 1, vi(maxh + 1, 1e9));
  dpb[0][0] = 0;
  dph[0][0] = 0;
  for (int i = 1; i <= b; ++i) {
    for (int j = 0; j <= maxb; ++j) {
      dpb[i][j] = dpb[i - 1][j];
      if (j >= bv[i - 1]) {
        dpb[i][j] = min(dpb[i][j], dpb[i - 1][j - bv[i - 1]] + 1);
      }
    }
  }

  for (int i = 1; i <= h; ++i) {
    for (int j = 0; j <= maxh; ++j) {
      dph[i][j] = dph[i - 1][j];
      if (j >= hv[i - 1]) {
        dph[i][j] = min(dph[i][j], dph[i - 1][j - hv[i - 1]] + 1);
      }
    }
  }

  int best = 1e9;
  for (int i = 1; i <= min(maxh, maxb); ++i) {
    best = min(best, dpb[b][i] + dph[h][i]);
  }

  if (best >= 1e9) {
    cout << "impossible";
  } else {
    cout << best;
  }
}
