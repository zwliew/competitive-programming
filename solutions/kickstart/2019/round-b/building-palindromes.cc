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

  int t;
  cin >> t;
  for (int ti = 1; ti <= t; ++ti) {
    cout << "Case #" << ti << ": ";
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<array<int, 26>> preSum(n + 1);
    for (int i = 1; i <= n; ++i) {
      preSum[i] = preSum[i - 1];
      preSum[i][s[i - 1] - 'A']++;
    }

    int ans = 0;
    while (q--) {
      int l, r;
      cin >> l >> r;
      --l;
      int odd = 0;
      auto freq = preSum[r];
      for (int i = 0; i < 26; ++i) {
        freq[i] -= preSum[l][i];
        if (freq[i] % 2) {
          ++odd;
        }
      }

      if (odd <= 1) {
        ++ans;
      }
    }

    cout << ans << "\n";
  }
}
