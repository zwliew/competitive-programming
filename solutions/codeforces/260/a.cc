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

  int a, b, n;
  cin >> a >> b >> n;

  if (a % b) {
    for (int i = 0; i < 10; ++i) {
      int next = a * 10 + i;
      if (next % b == 0) {
        a = next;
        --n;
        break;
      }
    }
  }

  if (a % b) {
    cout << -1;
    return 0;
  }

  cout << a;
  while (n--) {
    cout << 0;
  }
}
