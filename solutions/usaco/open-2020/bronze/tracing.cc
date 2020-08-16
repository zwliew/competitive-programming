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
#define FILE "tracing"
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int n, t;
  string target;
  cin >> n >> t >> target;

  vector<array<int, 3>> shakes(t);
  for (int i = 0; i < t; ++i) {
    cin >> shakes[i][0] >> shakes[i][1] >> shakes[i][2];
    --shakes[i][1];
    --shakes[i][2];
  }
  sort(shakes.begin(), shakes.end());

  unordered_set<int> x;
  int y = INT_MAX, z = 0;
  for (int i = 0; i < n; ++i) {
    if (target[i] == '0')
      continue;
    for (int k = 0; k <= t; ++k) {
      string cur(n, '0');
      vector<int> infected(n, -1);
      infected[i] = k;
      cur[i] = '1';
      for (int j = 0; j < t; ++j) {
        int a = shakes[j][1];
        int b = shakes[j][2];
        bool changed = false;
        if (infected[a] > 0) {
          infected[a]--;
          if (infected[b] == -1) {
            infected[b] = k;
            cur[b] = '1';
            changed = true;
          }
        }
        if (infected[b] > 0 && !changed) {
          infected[b]--;
          if (infected[a] == -1) {
            infected[a] = k;
            cur[a] = '1';
          }
        }
      }

      if (cur == target) {
        y = min(y, k);
        z = max(z, k);
        x.emplace(i);
      }
    }
  }

  cout << x.size() << ' ' << y << ' ' << (z == t ? "Infinity" : to_string(z));
}
