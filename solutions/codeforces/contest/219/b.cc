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

  int64_t p, d;
  cin >> p >> d;

  int origNines = 0;
  auto tmp = p;
  while (tmp % 10 == 9) {
    tmp /= 10;
    ++origNines;
  }

  int len = 0;
  tmp = p;
  while (tmp) {
    tmp /= 10;
    len++;
  }

  while (len) {
    if (len == origNines) {
      cout << p;
      return 0;
    }
    auto cur = p - p % __gnu_cxx::power<int64_t>(10, len) - 1;
    if (cur != -1 && p - cur <= d) {
      cout << cur;
      return 0;
    }
    --len;
  }

  cout << p;
}
