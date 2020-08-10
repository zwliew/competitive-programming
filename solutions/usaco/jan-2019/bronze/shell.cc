/*
ID: zhaowei10
TASK:
LANG: C++14
*/
#include "bits/stdc++.h"

using namespace std;

#ifdef LOCAL
#include "../../_library/cc/debug.h"
#define FILE "test"
#else
#define debug(...) 0
#define FILE "shell"
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int n;
  cin >> n;
  array<pair<int, int>, 3> cur;
  for (int i = 0; i < 3; ++i) {
    cur[i].first = i + 1;
  }

  while (n--) {
    int a, b, c;
    cin >> a >> b >> c;

    for (int i = 0; i < 3; ++i) {
      if (cur[i].first == a) {
        cur[i].first = b;
      } else if (cur[i].first == b) {
        cur[i].first = a;
      }

      if (c == cur[i].first) {
        ++cur[i].second;
      }
    }
  }

  int ans = 0;
  for (int i = 0; i < 3; ++i) {
    ans = max(ans, cur[i].second);
  }
  cout << ans;
}
