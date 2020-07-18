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

  int n, s;
  cin >> n >> s;

  // Better editorial solution
  int ans = s;
  while (n--) {
    int f, t;
    cin >> f >> t;
    ans = max(ans, f + t);
  }
  cout << ans;

  // My original solution
  // vector<int> latest(s + 1);
  // while (n--) {
  //   int f, t;
  //   cin >> f >> t;
  //   latest[f] = max(latest[f], t);
  // }

  // int cnt = latest[s];
  // int prev = latest[s];
  // for (int i = s - 1; i >= 0; --i) {
  //   ++prev;
  //   ++cnt;
  //   cnt += max(0, latest[i] - prev);
  //   prev = max(prev, latest[i]);
  // }
  // cout << cnt;

}
