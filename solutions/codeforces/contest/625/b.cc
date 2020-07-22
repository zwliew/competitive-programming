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

  string a, b;
  cin >> a >> b;
  int cnt = 0;
  for (int i = 0; i + (int)b.size() - 1 < (int)a.size(); ++i) {
    string c = a.substr(i, b.size());
    if (c == b) {
      a[i + (int)b.size() - 1] = '#';
      ++cnt;
    }
  }
  cout << cnt;
}
