#include <algorithm>
#include <array>
#include <bitset>
#include <chrono>
#include <climits>
#include <cmath>
#include <deque>
#include <ext/pb_ds/assoc_container.hpp>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
//#include "bits/stdc++.h"

using namespace std;

#ifdef LOCAL
#include "../../_library/cc/debug.h"
#define FILE "test"
#else
#define debug(...) 0
#define FILE "diamond"
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());

  vector<int> best(n), bestRev(n);
  for (int i = 0, j = 1; i < n; ++i) {
    while (j < n && a[j] - a[i] <= k) {
      ++j;
    }
    best[i] = j - i;
  }

  for (int i = n - 2; i >= 0; --i) {
    best[i] = max(best[i + 1], best[i]);
  }

  for (int i = 0, j = 0; i < n; ++i) {
    while (j < i && a[i] - a[j] > k) {
      ++j;
    }
    bestRev[i] = i - j + 1;
  }

  for (int i = 1; i < n; ++i) {
    bestRev[i] = max(bestRev[i - 1], bestRev[i]);
  }

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    ans = max(ans, best[i] + (i ? bestRev[i - 1] : 0));
  }
  cout << ans;
}
