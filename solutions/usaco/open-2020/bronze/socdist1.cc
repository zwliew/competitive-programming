#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "../../_library/cc/debug.h"
#define FILE "test"
#else
#define debug(...) 0
#define FILE "socdist1"
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int N;
  cin >> N;
  vector<int> dist;
  int last = -1;
  int first = -1;
  for (int i = 0; i < N; ++i) {
    char c;
    cin >> c;
    if (c == '1') {
      if (last != -1) {
        dist.push_back(i - last);
      } else {
        first = i;
      }
      last = i;
    }
  }

  if (first == -1) {
    cout << N - 1;
    return 0;
  }

  int best = INT_MIN;
  best = max(best, (N - 1 - last) / 2);
  best = max(best, first / 2);
  best = max(best, min(first, N - 1 - last));
  if (dist.empty()) {
    cout << best;
    return 0;
  }

  sort(dist.begin(), dist.end());
  best = max(best, dist.back() / 3);
  array<int, 4> cands = {dist.back() / 2, N - 1 - last, first, INT_MIN};
  if (dist.size() >= 2) {
    cands.back() = dist[dist.size() - 1] / 2;
  }
  sort(cands.begin(), cands.end());
  best = max(best, cands[2]);

  cout << min(dist[0], best);
}
