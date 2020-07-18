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
  vector<int> cnt(20);
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    int j = 0;
    while (x) {
      if (x & 1) ++cnt[j];
      j++;
      x >>= 1;
    }
  }

  long long ans = 0;
  bool changed = true;
  while (changed) {
    changed = false;
    long long cur = 0;
    for (int i = 0; i < 20; ++i) {
      if (cnt[i]) {
        cur += 1 << i;
        --cnt[i];
      }
    }
    changed = cur;
    ans += cur * cur;
  }

  cout << ans;
}
