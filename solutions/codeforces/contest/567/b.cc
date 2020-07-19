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
  unordered_set<int> inside;
  int mx = 0;
  while (n--) {
    char c;
    int x;
    cin >> c >> x;
    if (c == '-') {
      if (!inside.count(x)) {
        ++mx;
      } else {
        inside.erase(x);
      }
    } else {
      inside.emplace(x);
      mx = max<int>(mx, inside.size());
    }
  }
  cout << mx;
