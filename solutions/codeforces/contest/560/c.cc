/*
ID: zhaowei10
TASK:
LANG: C++14
*/
#include <ext/numeric>
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

  int x[6];
  for (int i = 0; i < 6; ++i) {
    cin >> x[i];
  }

  int overall = x[0] + x[1] + x[2];
  cout << overall * overall - x[0] * x[0] - x[2] * x[2] - x[4] * x[4];
}
