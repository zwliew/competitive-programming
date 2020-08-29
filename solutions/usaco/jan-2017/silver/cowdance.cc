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
#define FILE "cowdance"
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int n, tmax;
  cin >> n >> tmax;
  vector<int> d(n);
  for (auto& x : d)
    cin >> x;

  int l = 0, r = n;
  while (l < r - 1) {
    int m = l + (r - l) / 2;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; ++i) {
      int prev = 0;
      if (pq.size() == m) {
        prev = pq.top();
        pq.pop();
      }
      pq.emplace(prev + d[i]);
    }

    int t = 0;
    while (pq.size()) {
      t = pq.top();
      pq.pop();
    }

    if (t <= tmax) {
      r = m;
    } else {
      l = m;
    }
  }

  cout << r;
}
