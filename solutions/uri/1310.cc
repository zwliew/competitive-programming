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
  while (cin >> n) {
    int p;
    cin >> p;
    vector<int> v(n);
    for (int &x : v) {
      cin >> x;
      x -= p;
    }

    int best = 0;
    int cur = 0;
    for (int i = 0; i < n; ++i) {
      cur = max(0, cur) + v[i];
      best = max(best, cur);
    }

    cout << best << '\n';
  }
}
