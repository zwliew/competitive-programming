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
#define FILE "homework"
#endif

int comp(int a, int b) {
  return min(a, b);
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int n;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  vector<int> sufMin(n + 1);
  partial_sum(a.rbegin(), a.rend(), sufMin.rbegin(), comp);

  vector<int> bestIndices;
  int64_t bestNum = 0, bestDenom = 1;
  int sum = accumulate(a.begin(), a.end(), 0);
  for (int i = 1; i <= n - 2; ++i) {
    sum -= a[i];
    int64_t scoreNum = sum - sufMin[i + 1];
    int64_t scoreDenom = (n - i - 1);
    if (scoreNum * bestDenom > bestNum * scoreDenom) {
      bestIndices = {i};
      bestNum = scoreNum;
      bestDenom = scoreDenom;
    } else if (scoreNum * bestDenom == bestNum * scoreDenom) {
      bestIndices.emplace_back(i);
    }
  }

  for (int x : bestIndices) {
    cout << x << '\n';
  }
}
