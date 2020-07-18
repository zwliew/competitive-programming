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
  long long a = 0, b = 0;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    a |= x;
  }
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    b |= x;
  }
  cout << a + b;
}
