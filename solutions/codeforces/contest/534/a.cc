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

  if (n == 2) {
    cout << "1\n1";
  } else if (n == 3) {
    cout << "2\n1 3";
  } else {
    cout << n << '\n';
    for (int i = n - !(n & 1); i >= 1; i -= 2) {
      cout << i << ' ';
    }
    for (int i = n - (n & 1); i >= 2; i -= 2) {
      cout << i << ' ';
    }
  }
}
