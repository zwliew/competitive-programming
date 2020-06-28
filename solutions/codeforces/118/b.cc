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
  for (int i = 0; i <= n; ++i) {
    for (int j = n; j > i; --j) {
      cout << "  ";
    }
    for (int j = 0; j <= i; ++j) {
      cout << j;
      if (i)
        cout << ' ';
    }
    for (int j = i - 1; j >= 0; --j) {
      cout << j;
      if (j) {
        cout << ' ';
      }
    }
    cout << '\n';
  }
  for (int i = n - 1; i >= 0; --i) {
    for (int j = n; j > i; --j) {
      cout << "  ";
    }
    for (int j = 0; j <= i; ++j) {
      cout << j;
      if (i)
        cout << ' ';
    }
    for (int j = i - 1; j >= 0; --j) {
      cout << j;
      if (j) {
        cout << ' ';
      }
    }
    cout << '\n';
  }
}
