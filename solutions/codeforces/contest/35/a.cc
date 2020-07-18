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

  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int cur;
  cin >> cur;
  for (int i = 0; i < 3; ++i) {
    int a, b;
    cin >> a >> b;
    if (a == cur) {
      cur = b;
    } else if (b == cur) {
      cur = a;
    }
  }
  cout << cur;
}
