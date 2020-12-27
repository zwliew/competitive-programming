/*
ID: zhaowei10
LANG: C++14
TASK:
*/
#include <bits/stdc++.h>
using namespace std;
#define debug(...) 0
#ifdef LOCAL
#include "../../_library/cc/debug.h"
#endif
// #define FILE "milk2"

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
#if defined(FILE) && !defined(LOCAL)
  freopen(FILE ".in", "r", stdin), freopen(FILE ".out", "w", stdout);
#endif

  int N;
  cin >> N;
  vector<int> A(N);
  for (auto& x : A)
    cin >> x;
  int64_t ans = 0;
  int64_t cur = 0;
  for (int x : A) {
    ans += x * cur;
    cur += x;
  }
  cout << ans;
}
