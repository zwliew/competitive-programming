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

  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    int ans = 0;
    int curDist = k;
    int lastIdx = -1e8;
    for (int i = 0; i < n; ++i) {
      if (s[i] == '1') {
        curDist = 0;
        lastIdx = i;
      } else {
        ++curDist;
      }

      if (curDist > k * 2) {
        curDist = k;
        ++ans;
        lastIdx = max(0, i - k);
      }
    }

    if (n - 1 - lastIdx > k) {
      ++ans;
    }

    cout << ans << '\n';
  }
}
