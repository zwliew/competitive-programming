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
#include <debug.h>
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

  int h, w;
  cin >> h >> w;
  ld total = 0;
  int cnt = 0;
  for (int i = 0; i < h - 1; ++i) {
    for (int j = 0; j < w; ++j) {
      char c;
      cin >> c;
      if (c != '.') {
        total += j + (ld)0.5;
        ++cnt;
      }
    }
  }

  int first = -1, last;
  for (int i = 0; i < w; ++i) {
    char c;
    cin >> c;
    if (c != '.') {
      if (first == -1) first = i;
      last = i;
      total += i + (ld)0.5;
      ++cnt;
    }
  }

  ld mean = total / cnt;
  debug(total, cnt, mean, first, last);
  if (mean < first) {
    cout << "left";
  } else if (mean > last + 1) {
    cout << "right";
  } else {
    cout << "balanced";
  }
}
