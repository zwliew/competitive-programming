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
#define FILE "mountains"
#endif

bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
  if (a.first == b.first) {
    return a.second > b.second;
  }
  return a.first < b.first;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int n;
  cin >> n;
  vector<pair<int, int>> mtns;
  for (int i = 0; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    mtns.emplace_back(x - y, x + y);
  }
  sort(mtns.begin(), mtns.end(), cmp);

  int cnt = 0;
  int greatestSum = -1;
  for (int i = 0; i < n; ++i) {
    cnt += mtns[i].second > greatestSum;
    greatestSum = max(greatestSum, mtns[i].second);
  }
  cout << cnt;
}
