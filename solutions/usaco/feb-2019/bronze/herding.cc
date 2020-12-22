#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "../../_library/cc/debug.h"
#define FILE "test"
#else
#define debug(...) 0
#define FILE "herding"
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  array<int, 3> a;
  cin >> a[0] >> a[1] >> a[2];
  sort(a.begin(), a.end());

  // Editorial solution
  if (a[2] == a[0] + 2) {
    cout << 0;
  } else if (a[1] == a[0] + 2 || a[2] == a[1] + 2) {
    cout << 1;
  } else {
    cout << 2;
  }
  cout << "\n" << max(a[2] - a[1], a[1] - a[0]) - 1;

  // Original solution
  // int x = a[1] - a[0] - 1;
  // int y = a[2] - a[1] - 1;
  // if (a[0] == a[1] - 1 && a[1] == a[2] - 1) {
  //   cout << "0\n0";
  // } else if (a[1] - a[0] == 1) {
  //   cout << min(2, y) << "\n" << y;
  // } else if (a[2] - a[1] == 1) {
  //   cout << min(2, x) << "\n" << x;
  // } else {
  //   cout << min({2, x, y}) << "\n" << max(x, y);
  // }
}
