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

  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    map<int, int64_t> needed;
    for (int i = 0; i < N; ++i) {
      int L, R, Z;
      cin >> L >> R >> Z;
      needed[R] += Z;
    }
    for (auto it = needed.begin(); next(it) != needed.end(); ++it) {
      next(it)->second += it->second;
    }

    int64_t rate = INT_MIN;
    for (auto& [k, v] : needed) {
      rate = max(rate, (v + k - 1) / k);
    }
    cout << rate << "\n";
  }
}
