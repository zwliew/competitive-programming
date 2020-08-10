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
#define FILE "hps"
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  // Consider all 3! different permutations
  // int n;
  // cin >> n;
  // vector<pair<int, int>> games(n);
  // for (int i = 0; i < n; ++i) {
  //   cin >> games[i].first >> games[i].second;
  //   --games[i].first;
  //   --games[i].second;
  // }
  // array<int, 3> a{0, 1, 2};
  // int best = 0;
  // do {
  //   int won = 0;
  //   for (int i = 0; i < n; ++i) {
  //     int x = games[i].first;
  //     int y = games[i].second;
  //     if ((a[x] == 0 && a[y] == 1) || (a[x] == 1 && a[y] == 2) ||
  //         (a[x] == 2 && a[y] == 0)) {
  //       ++won;
  //     }
  //   }
  //   best = max(best, won);
  // } while (next_permutation(a.begin(), a.end()));
  // cout << best;

  // Alternative solution using the fact that there are only 2 distinct sets of
  // win conditions (the win conditions form a directed cyclic graph)
  int n;
  cin >> n;
  array<array<int, 3>, 3> matches;
  for (auto& x : matches)
    fill(x.begin(), x.end(), 0);
  for (int i = 0; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    matches[a - 1][b - 1]++;
  }

  cout << max(matches[0][1] + matches[1][2] + matches[2][0],
              matches[1][0] + matches[2][1] + matches[0][2]);
}
