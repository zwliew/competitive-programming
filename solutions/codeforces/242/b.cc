/*
ID: zhaowei10
TASK:
LANG: C++14
*/
#include "bits/stdc++.h"

using namespace std;

#ifdef LOCAL
#include "../../_library/cpp/debug.h"
#define FILE "test"
#else
#define debug(...) 0
#define FILE ""
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int n;
  cin >> n;
  int l = INT_MAX, r = INT_MIN;
  vector<pair<int, int>> segments;
  for (int i = 0; i < n; ++i) {
    int li, ri;
    cin >> li >> ri;
    segments.emplace_back(li, ri);
    l = min(li, l);
    r = max(ri, r);
  }

  for (int i = 0; i < n; ++i) {
    if (segments[i].first == l && r == segments[i].second) {
      cout << i + 1;
      return 0;
    }
  }
  cout << -1;
}
