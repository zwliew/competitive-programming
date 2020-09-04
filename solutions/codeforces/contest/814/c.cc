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

  int n;
  cin >> n;
  string s;
  cin >> s;
  array<vector<int>, 26> cnt;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 26; ++j) {
      cnt[j].emplace_back((cnt[j].empty() ? 0 : cnt[j].back()) +
                          (s[i] - 'a' != j));
    }
  }

  array<vector<int>, 26> ans;
  for (int m = 1; m <= n; ++m) {
    for (int c = 0; c < 26; ++c) {
      int best = 0;
      for (int i = 0, j = 1; i < n; ++i) {
        while (j < n && cnt[c][j] - (i ? cnt[c][i - 1] : 0) <= m) {
          ++j;
        }
        best = max(best, j - i);
      }
      ans[c].emplace_back(best);
    }
  }

  int q;
  cin >> q;
  while (q--) {
    int m;
    char c;
    cin >> m >> c;
    cout << ans[c - 'a'][m - 1] << '\n';
  }
}
