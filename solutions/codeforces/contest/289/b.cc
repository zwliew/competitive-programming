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

  int n, m, d;
  cin >> n >> m >> d;
  int ans = 0;
  vector<int> a(n * m);
  for (int &x : a) {
    cin >> x;
  }

  nth_element(a.begin(), a.begin() + n * m / 2, a.end());
  for (int x : a) {
    int diff = abs(a[n * m / 2] - x);
    if (diff % d) {
      cout << -1;
      return 0;
    }
    ans += diff / d;
  }
  cout << ans;
}
