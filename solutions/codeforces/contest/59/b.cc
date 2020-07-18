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
  int minodd = INT_MAX;
  int sum = 0;
  while (n--) {
    int x;
    cin >> x;
    if (x % 2) {
      minodd = min(minodd, x);
    }
    sum += x;
  }
  if (sum % 2 == 0 && minodd == INT_MAX) {
    cout << 0;
    return 0;
  }
  cout << sum - (sum % 2 ? 0 : minodd);
}
