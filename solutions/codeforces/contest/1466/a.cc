#include <bits/stdc++.h>
using namespace std;
#define debug(...) 0
#ifdef LOCAL
#include "../../_library/cc/debug.h"
#endif
// #define FILE "milkvisits"

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
    vector<int> X(N);
    for (auto& x : X)
      cin >> x;

    unordered_set<int> areas;
    for (int i = 0; i < N; ++i) {
      for (int j = i + 1; j < N; ++j) {
        areas.insert(X[j] - X[j]);
      }
    }
    cout << areas.size() << "\n";
  }
}
