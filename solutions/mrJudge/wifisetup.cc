#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "../../_library/cc/debug.h"
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

  int N, M;
  cin >> N >> M;
  vector<int> pos(N);
  for (int i = 0; i < N; ++i) {
    cin >> pos[i];
  }
  sort(pos.begin(), pos.end());

  vector<int> dist(N - 1);
  for (int i = 0; i < N - 1; ++i) {
    dist[i] = pos[i + 1] - pos[i];
  }
  sort(dist.begin(), dist.end());

  vector<int64_t> distsum(N - 1);
  partial_sum(dist.begin(), dist.end(), distsum.begin());

  while (M--) {
    int A, B;
    cin >> A >> B;

    auto idx =
        upper_bound(dist.begin(), dist.end(), (double)A / B * 2) - dist.begin();
    int64_t total = (dist.size() - idx + 1) * A * 2;
    if (idx) {
      total += distsum[idx - 1] * B;
    }

    cout << total / 2;
    if (total % 2) {
      cout << ".5";
    }
    cout << '\n';
  }
}
