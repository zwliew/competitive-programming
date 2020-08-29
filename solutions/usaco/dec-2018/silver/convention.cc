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
#define FILE "convention"
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int n, m, c;
  cin >> n >> m >> c;
  vector<int> arrived(n);
  for (auto& x : arrived)
    cin >> x;
  sort(arrived.begin(), arrived.end());

  int l = -1, r = 1e9;
  while (l < r - 1) {
    int mid = l + (r - l) / 2;

    int firstArrived = -1e9;
    int buses = 0;
    int capacity = 0;
    for (int i = 0; i < n; ++i) {
      if (capacity == c || arrived[i] - firstArrived > mid) {
        firstArrived = arrived[i];
        ++buses;
        capacity = 0;
      }
      ++capacity;
    }

    if (buses <= m) {
      r = mid;
    } else {
      l = mid;
    }
  }

  cout << r;
}
