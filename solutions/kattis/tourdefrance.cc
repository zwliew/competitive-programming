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

  int F;
  while (cin >> F && F) {
    int R;
    cin >> R;
    vector<int> front(F), rear(R);
    for (auto& x : front)
      cin >> x;
    for (auto& x : rear)
      cin >> x;

    vector<double> pairs(F * R);
    for (int i = 0; i < F; ++i) {
      for (int j = 0; j < R; ++j) {
        pairs[i * R + j] = (double)rear[j] / front[i];
      }
    }
    sort(pairs.begin(), pairs.end());

    double ans = 0;
    for (int i = 0; i < F * R - 1; ++i) {
      ans = max(ans, pairs[i + 1] / pairs[i]);
    }
    cout << fixed << setprecision(2) << ans << "\n";
  }
}
