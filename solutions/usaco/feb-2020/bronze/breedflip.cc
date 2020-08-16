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
#define FILE "breedflip"
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int n;
  cin >> n;
  string a, b;
  cin >> a >> b;

  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    int j = i;
    while (j < n && a[j] != b[j])
      ++j;
    if (j > i) {
      ++cnt;
      i = j - 1;
    }
  }
  cout << cnt;
}
