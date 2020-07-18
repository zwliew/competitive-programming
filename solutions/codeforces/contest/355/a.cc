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

  int k, d;
  cin >> k >> d;
  if (!d && k > 1) {
    cout << "No solution";
    return 0;
  }
  cout << d;
  for (int i = 0; i < k - 1; ++i) {
    cout << 0;
  }
}
