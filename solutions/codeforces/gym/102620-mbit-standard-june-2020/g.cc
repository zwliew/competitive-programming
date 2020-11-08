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
#include <iterator>
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

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int N;
  cin >> N;
  vector<char> arr(N);
  for (auto& x : arr)
    cin >> x;

  // Official greedy solution
  for (int i = 1; i < N; ++i) {
    if (arr[i] == 'B' && arr[i - 1] != 'B') {
      arr[i] = arr[i - 1] == 'U' ? 'D' : 'U';
    }
  }
  for (int i = N - 1; i >= 0; --i) {
    if (arr[i] == 'B') {
      if (i == N - 1) {
        arr[i] = 'U';
      } else {
        arr[i] = arr[i + 1] == 'U' ? 'D' : 'U';
      }
    }
  }

  for (char x : arr)
    cout << x << " ";

  // Original DP solution
  // vector<vector<int>> dp(N, vector<int>(2, 1e9)), p(N, vector<int>(2, -1));
  // if (arr[0] == 'U' || arr[0] == 'B') {
  //   dp[0][1] = 0;
  // }
  // if (arr[0] == 'D' || arr[0] == 'B') {
  //   dp[0][0] = 0;
  // }
  // for (int i = 1; i < N; ++i) {
  //   if (arr[i] == 'B' || arr[i] == 'U') {
  //     int a = dp[i - 1][1] + 1;
  //     int b = dp[i - 1][0];
  //     if (a < b) {
  //       dp[i][1] = a;
  //       p[i][1] = 1;
  //     } else {
  //       dp[i][1] = b;
  //       p[i][1] = 0;
  //     }
  //   }
  //   if (arr[i] == 'B' || arr[i] == 'D') {
  //     int a = dp[i - 1][0] + 1;
  //     int b = dp[i - 1][1];
  //     if (a < b) {
  //       dp[i][0] = a;
  //       p[i][0] = 0;
  //     } else {
  //       dp[i][0] = b;
  //       p[i][0] = 1;
  //     }
  //   }
  // }

  // int idx = dp[N - 1][1] < dp[N - 1][0];
  // string ans;
  // for (int i = N - 1; i >= 0; --i) {
  //   if (idx) {
  //     ans += 'U';
  //   } else {
  //     ans += 'D';
  //   }
  //   idx = p[i][idx];
  // }
  // reverse(ans.begin(), ans.end());
  // for (char c : ans) {
  //   cout << c << " ";
  // }
}
