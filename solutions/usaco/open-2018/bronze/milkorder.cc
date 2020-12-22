#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "../../_library/cc/debug.h"
#define FILE "test"
#else
#define debug(...) 0
#define FILE "milkorder"
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int N, M, K;
  cin >> N >> M >> K;

  vector<int> relative(M);
  for (int i = 0; i < M; ++i) {
    cin >> relative[i];
    --relative[i];
  }

  vector<int> pos(N, -1), cow(N, -1);
  for (int i = 0; i < K; ++i) {
    int c, p;
    cin >> c >> p;
    --c, --p;
    pos[c] = p;
    cow[p] = c;
    if (c == 0) {
      cout << p + 1;
      return 0;
    }
  }

  for (int i = 0; i < N; ++i) {
    if (cow[i] != -1)
      continue;

    cow[i] = 0;
    pos[0] = i;
    int k = 0, j = 0;
    while (k < M && j < N) {
      if (cow[j] == relative[k]) {
        ++j;
        ++k;
      } else if (cow[j] != -1) {
        ++j;
      } else if (pos[relative[k]] == -1) {
        ++j;
        ++k;
      } else if (pos[relative[k]] < j) {
        break;
      } else {
        j = pos[relative[k]] + 1;
        ++k;
      }
    }

    if (k == M) {
      cout << i + 1;
      return 0;
    }
    cow[i] = -1;
    pos[0] = -1;
  }
}
