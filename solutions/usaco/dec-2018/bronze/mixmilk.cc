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
#define FILE "mixmilk"
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  array<int, 3> c, m;
  for (int i = 0; i < 3; ++i) {
    cin >> c[i] >> m[i];
  }

  for (int i = 1; i <= 100; ++i) {
    int cidx = i % 3;
    int pidx = (i + 2) % 3;
    int poured = min(m[pidx], c[cidx] - m[cidx]);
    m[cidx] += poured;
    m[pidx] -= poured;
  }

  cout << m[0] << '\n' << m[1] << '\n' << m[2];
}
