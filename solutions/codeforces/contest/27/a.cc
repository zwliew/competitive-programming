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
  vector<bool> used(3002);
  while (n--) {
    int x;
    cin >> x;
    used[x] = true;
  }

  for (int i = 1; i <= 3001; ++i) {
    if (!used[i]) {
      cout << i;
      return 0;
    }
  }
}
