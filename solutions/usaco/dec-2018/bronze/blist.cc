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
#define FILE "blist"
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  // Brute force solution
  // int n;
  // cin >> n;
  // int ans = 0;
  // vector<pair<int, int>> cows(n);
  // vector<int> buckets(n);
  // for (int i = 0; i < n; ++i) {
  //   cin >> cows[i].first >> cows[i].second >> buckets[i];
  // }
  // for (int i = 1; i <= 1000; ++i) {
  //   int cur = 0;
  //   for (int j = 0; j < n; ++j) {
  //     if (cows[j].first <= i && cows[j].second >= i) {
  //       cur += buckets[j];
  //     }
  //   }
  //   ans = max(ans, cur);
  // }
  // cout << ans;

  // Faster solution using sorting and a sweepline
  int n;
  cin >> n;
  vector<pair<int, int>> times;
  for (int i = 0; i < n; ++i) {
    int s, t, b;
    cin >> s >> t >> b;
    times.emplace_back(s, b);
    times.emplace_back(t, -b);
  }
  sort(times.begin(), times.end());

  int cur = 0, ans = 0;
  for (int i = 0; i < times.size(); ++i) {
    cur += times[i].second;
    ans = max(ans, cur);
  }
  cout << ans;
}
