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
#define FILE ""
#endif

struct Item {
  int s, e, l;
  Item() {}
  Item(int _s, int _e, int _l) : s(_s), e(_e), l(_l) {}

  bool operator<(auto& other) const { return l * other.s > s * other.l; }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int t;
  cin >> t;
  for (int ti = 1; ti <= t; ++ti) {
    cout << "Case #" << ti << ": ";
    int n;
    cin >> n;
    vector<Item> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i].s >> a[i].e >> a[i].l;
    }
    sort(a.begin(), a.end());
    vector<vector<int>> dp(n + 1, vector<int>(10001));
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= 10000; ++j) {
        dp[i][j] = dp[i - 1][j];
        int start = j - a[i - 1].s;
        if (start >= 0) {
          dp[i][j] = max(dp[i][j], dp[i - 1][start] +
                                       max(0, a[i - 1].e - a[i - 1].l * start));
        }
      }
    }
    cout << *max_element(dp[n].begin(), dp[n].end()) << "\n";
  }
}
