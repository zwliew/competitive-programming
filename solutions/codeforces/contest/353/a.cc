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
  int upper = 0, lower = 0;
  bool has = false;
  while (n--) {
    int a, b;
    cin >> a >> b;
    upper += a;
    lower += b;
    if ((a % 2 || b % 2) && !(a % 2 && b % 2)) {
      has = true;
    }
  }

  if (upper % 2 == 0 && lower % 2 == 0) {
    cout << 0;
  } else if (upper % 2 && lower % 2) {
    cout << (has ? 1 : -1);
  } else {
    cout << -1;
  }
}
