#include <bits/stdc++.h>
using namespace std;
#define debug(...) 0
#ifdef LOCAL
#include "../../_library/cc/debug.h"
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
#if defined(FILE) && !defined(LOCAL)
  freopen(FILE ".in", "r", stdin), freopen(FILE ".out", "w", stdout);
#endif

  int N;
  cin >> N;
  while (N--) {
    vector<int> stats(5, -1);
    for (int i = 0; i < 5; ++i) {
      string s;
      cin >> s;
      if (s != "?") {
        stats[i] = stoi(s);
      }
    }

    if (stats[0] == -1 && stats[3] == -1)
      stats[3] = 0;

    bool ok = false;
    for (int b = 0; b <= 100 && !ok; ++b) {
      if (stats[1] != -1 && b != stats[1])
        continue;
      for (int c = 0; c <= 100 && !ok; ++c) {
        if (stats[2] != -1 && c != stats[2])
          continue;
        int a = stats[0] == -1 ? b + c + stats[3] : stats[0];
        int d = stats[3] == -1 ? a - b - c : stats[3];
        int e = stats[4] == -1 ? b * 3 + c : stats[4];
        if (a == b + c + d && a >= 0 && a <= 100 && e == b * 3 + c && d >= 0 &&
            d <= 100) {
          cout << a << " " << b << " " << c << " " << d << " " << e << "\n";
          ok = true;
        }
      }
    }
  }
}
