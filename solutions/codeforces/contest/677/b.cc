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

  int n, h, k;
  cin >> n >> h >> k;
  vector<int> a(n);
  for (auto& x : a)
    cin >> x;

  int64_t sec = 0;
  int rem = 0;
  for (int i = 0; i < n;) {
    if (rem + a[i] > h) {
      ++sec;
      rem = 0;
    }

    while (i < n && rem + a[i] <= h) {
      rem += a[i];
      ++i;
    }

    int dt = rem / k;
    sec += dt;
    rem -= dt * k;
  }
  cout << sec + (rem > 0);
}
