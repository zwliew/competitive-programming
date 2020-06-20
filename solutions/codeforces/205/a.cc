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

  int minDist = INT_MAX;
  int cnt = 0;
  int idx = 0;
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    if (x < minDist) {
      cnt = 1;
      idx = i;
      minDist = x;
    } else if (x == minDist) {
      ++cnt;
    }
  }

  cout << (cnt > 1 ? "Still Rozdil" : to_string(idx));
}
