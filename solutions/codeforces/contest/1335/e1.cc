#include <stdio.h>

#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <deque>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

using ll = long long;
using ld = long double;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    // prefixSum[i][j] = prefix sum of char i using the first j characters
    // (0..j-1)
    vector<vector<int>> prefixSum(27, vector<int>(n + 1));
    vector<int> a(n);
    for (int j = 0; j < n; ++j) {
      cin >> a[j];
      for (int i = 1; i <= 26; ++i) {
        prefixSum[i][j + 1] = prefixSum[i][j];
        if (a[j] == i) {
          ++prefixSum[i][j + 1];
        }
      }
    }

    int tmax = 0;
    for (int i = 1; i <= 26; ++i) {
      tmax = max(tmax, prefixSum[i][n]);
    }

    for (int l = 0; l < n; ++l) {
      for (int r = l + 1; r < n; ++r) {
        for (int c1 = 1; c1 <= 26; ++c1) {
          for (int c2 = 1; c2 <= 26; ++c2) {
            if (c2 == c1) continue;
            if (prefixSum[c1][l + 1] != prefixSum[c1][n] - prefixSum[c1][r])
              continue;
            int cur =
                prefixSum[c1][l + 1] + prefixSum[c1][n] - prefixSum[c1][r];
            cur += prefixSum[c2][r] - prefixSum[c2][l + 1];
            tmax = max(tmax, cur);
          }
        }
      }
    }
    cout << tmax << '\n';
  }
}
