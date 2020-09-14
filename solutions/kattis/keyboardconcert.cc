#include <algorithm>
#include <array>
#include <bitset>
#include <chrono>
#include <climits>
#include <cmath>
#include <cstring>
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
// #include "bits/stdc++.h"

using namespace std;

#ifdef LOCAL
#include "../../_library/cc/debug.h"
#define FILE "test"
#else
#define debug(...) 0
#define FILE "cowjog"
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  // dp[i][j] = min number of switches to play all the notes including the i-th
  // note, while ending in instrument j
  int n, m;
  cin >> n >> m;

  vector<unordered_set<int>> playable(n);
  for (int i = 0; i < n; ++i) {
    int k;
    cin >> k;
    while (k--) {
      int l;
      cin >> l;
      playable[i].insert(l);
    }
  }

  vector<int> dp(n), nxtdp(n);
  for (int i = 0; i < m; ++i) {
    int x;
    cin >> x;

    int mn = min_element(dp.begin(), dp.end()) - dp.begin();
    for (int j = 0; j < n; ++j) {
      if (!playable[j].count(x)) {
        nxtdp[j] = 1e9;
      } else {
        nxtdp[j] = min(dp[j], dp[mn] + 1);
      }
    }
    swap(dp, nxtdp);
  }

  cout << *min_element(dp.begin(), dp.end());
}
