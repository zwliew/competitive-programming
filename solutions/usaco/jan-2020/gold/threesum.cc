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

using namespace std;

#ifdef LOCAL
#include "../../_library/cc/debug.h"
#define FILE "test"
#else
#define debug(...) 0
#define FILE "threesum"
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (int i = 0; i < n; ++i)
    cin >> a[i];

  const int off = 1e6;
  vector<vector<int64_t>> ans(n + 1, vector<int64_t>(n + 1));
  vector<int> cnt(2 * off + 1);
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      int id = off - a[i] - a[j];
      if (id >= 0 && id <= 2e6)
        ans[i][j] += cnt[-a[i] - a[j] + off];
      ++cnt[a[j] + off];
    }
    for (int j = i + 1; j < n; ++j) {
      --cnt[a[j] + off];
    }
  }

  for (int i = n - 1; i >= 0; --i) {
    for (int j = i + 1; j < n; ++j) {
      ans[i][j] += ans[i][j - 1] + ans[i + 1][j] - ans[i + 1][j - 1];
    }
  }

  while (q--) {
    int l, r;
    cin >> l >> r;
    cout << ans[l - 1][r - 1] << "\n";
  }
}
