/*
ID: zhaowei10
TASK:
LANG: C++14
*/
#include "bits/stdc++.h"

using namespace std;

#ifdef LOCAL
#include "../../_library/cpp/debug.h"
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

  int n, m;
  cin >> n >> m;

  // Simulation solution
  // queue<pair<int, int>> q;
  // for (int i = 0; i < n; ++i) {
  //   int x;
  //   cin >> x;
  //   q.emplace(x, i + 1);
  // }

  // int last = 1;
  // while (q.size()) {
  //   auto &[x, i] = q.front();
  //   q.pop();
  //   x -= m;
  //   last = i;
  //   if (x > 0) {
  //     q.emplace(x, i);
  //   }
  // }
  // cout << last;

  // Better solution using observation
  int lastIdx = 1;
  int curMax = 0;
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    if ((x + m - 1) / m >= curMax) {
      curMax = (x + m - 1) / m;
      lastIdx = i;
    }
  }
  cout << lastIdx;
}
