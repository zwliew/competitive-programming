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
#define FILE "cowqueue"
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int n;
  cin >> n;
  vector<pair<int, int>> cows(n);
  for (int i = 0; i < n; ++i) {
    cin >> cows[i].first >> cows[i].second;
  }
  sort(cows.begin(), cows.end());

  int time = 0;
  for (int i = 0; i < n; ++i) {
    time = max(cows[i].first, time) + cows[i].second;
  }
  cout << time;
}
