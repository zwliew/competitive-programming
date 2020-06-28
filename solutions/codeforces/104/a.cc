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
  n -= 10;
  
  if (n <= 0) {
    cout << 0;
  } else if (n <= 9) {
    cout << 4;
  } else if (n == 10) {
    cout << 15;
  } else if (n == 11) {
    cout << 4;
  } else {
    cout << 0;
  }
}
