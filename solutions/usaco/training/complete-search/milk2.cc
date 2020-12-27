/*
ID: zhaowei10
LANG: C++14
TASK: milk2
*/
#include <bits/stdc++.h>
using namespace std;
#define debug(...) 0
#ifdef LOCAL
#include "../../_library/cc/debug.h"
#endif
#define FILE "milk2"

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
#if defined(FILE) && !defined(LOCAL)
  freopen(FILE ".in", "r", stdin), freopen(FILE ".out", "w", stdout);
#endif

  int N;
  cin >> N;
  vector<array<int, 2>> events(N * 2);
  for (int i = 0; i < N; ++i) {
    int s, e;
    cin >> s >> e;
    events[i * 2] = {s, 1};
    events[i * 2 + 1] = {e, -1};
  }
  sort(events.begin(), events.end());

  array<int, 2> best = {0, 0};
  int cur = 0;
  int prev = 0;
  int start = 0;
  for (int i = 0; i < N * 2; ++i) {
    cur += events[i][1];
    if (i + 1 < N * 2 && events[i + 1][0] == events[i][0])
      continue;
    if ((bool)prev != (bool)cur) {
      best[cur >= 1] = max(best[cur >= 1], events[i][0] - events[start][0]);
      start = i;
    }
    prev = cur;
  }
  cout << best[0] << " " << best[1] << "\n";
}
