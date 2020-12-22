#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "../../_library/cc/debug.h"
#define FILE "test"
#else
#define debug(...) 0
#define FILE "wifi"
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int N, A, B;
  cin >> N >> A >> B;
  vector<int> pos(N);
  for (int i = 0; i < N; ++i) {
    cin >> pos[i];
  }
  sort(pos.begin(), pos.end());

  int total = A * 2;
  for (int i = 1; i < N; ++i) {
    int f = A * 2;
    int s = (pos[i] - pos[i - 1]) * B;
    total += min(f, s);
  }

  cout << total / 2;
  if (total % 2) {
    cout << ".5";
  }
}
