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
  int fives = 0, zeros = 0;
  while (n--) {
    int x;
    cin >> x;
    if (x)
      fives++;
    else
      zeros++;
  }

  fives = fives / 9 * 9;
  if (!zeros) {
    cout << -1;
    return 0;
  }
  if (!fives) {
    cout << 0;
    return 0;
  }

  while (fives--) {
    cout << 5;
  }
  while (zeros--) {
    cout << 0;
  }
}
