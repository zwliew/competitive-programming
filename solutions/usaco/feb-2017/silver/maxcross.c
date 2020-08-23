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
#define FILE "maxcross"
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int n, k, b;
  cin >> n >> k >> b;

  // O(BlogB) solution (better if B is small and N is too large)
  vector<int> broken(b);
  for (int i = 0; i < b; ++i) {
    cin >> broken[i];
  }
  sort(broken.begin(), broken.end());

  int j = 0;
  while (j < b && broken[j] <= k)
    ++j;

  int best = j;
  for (int i = 0; i < b; ++i) {
    if (broken[i] + k > n)
      break;
    while (j < b && broken[i] + k >= broken[j])
      ++j;
    best = min(best, j - i - 1);
  }
  cout << best;

  // O(N) solution
  // vector<bool> broken(n);
  // for (int i = 0; i < b; ++i) {
  //   int x;
  //   cin >> x;
  //   --x;
  //   broken[x] = true;
  // }
  // int cur = accumulate(broken.begin(), broken.begin() + k, 0);
  // int best = cur;
  // for (int i = k; i < n; ++i) {
  //   cur += broken[i];
  //   cur -= broken[i - k];
  //   best = min(best, cur);
  // }
  // cout << best;
}
