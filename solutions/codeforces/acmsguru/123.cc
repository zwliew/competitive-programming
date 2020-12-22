#include <bits/stdc++.h>

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

  int K;
  cin >> K;
  int64_t a = 1, b = 1;
  int64_t sum = a + b;
  for (int i = 3; i <= K; ++i) {
    a += b;
    swap(a, b);
    sum += b;
  }
  if (K == 1) {
    cout << a;
  } else {
    cout << sum;
  }
}
