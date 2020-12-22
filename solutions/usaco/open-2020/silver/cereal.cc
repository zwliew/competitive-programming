#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "../../_library/cc/debug.h"
#define FILE "test"
#else
#define debug(...) 0
#define FILE "cereal"
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int N, M;
  cin >> N >> M;
  vector<array<int, 2>> V(N);
  for (auto& v : V) {
    cin >> v[0] >> v[1];
  }

  vector<int> ans(N + 1);
  vector<int> used(M + 1, -1);
  for (int i = N - 1; i >= 0; --i) {
    ans[i] = ans[i + 1];
    int j = i;
    int pos = V[i][0];
    while (true) {
      // Editorial solution
      if (used[pos] == -1) {
        ++ans[i];
        used[pos] = j;
        break;
      }

      if (used[pos] < j) {
        break;
      }

      swap(used[pos], j);
      if (pos == V[j][1]) {
        break;
      }
      pos = V[j][1];

      // Original solution
      // if (used[V[j][0]] == -1) {
      //   ++ans[i];
      //   used[V[j][0]] = j;
      //   break;
      // }

      // if (used[V[j][0]] > j) {
      //   swap(used[V[j][0]], j);
      // } else {
      //   if (used[V[j][1]] == -1) {
      //     ++ans[i];
      //     used[V[j][1]] = j;
      //     break;
      //   }

      //   if (used[V[j][1]] < j) {
      //     break;
      //   }
      //   swap(used[V[j][1]], j);
      // }
    }
  }

  for (int i = 0; i < N; ++i) {
    cout << ans[i] << "\n";
  }
}
