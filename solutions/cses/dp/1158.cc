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

typedef long long ll;
typedef long double ld;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  // Improved solution in terms of mainly memory (which also affects time)
  int N, X;
  cin >> N >> X;
  vector<int> H(N), S(N);
  for (auto& x : H)
    cin >> x;
  for (auto& x : S)
    cin >> x;
  vector<int> dp(X + 1);
  for (int i = 0; i < N; ++i) {
    int h = H[i];
    int s = S[i];
    for (int j = X; j >= h; --j) {
      dp[j] = max(dp[j], dp[j - h] + s);
    }
  }
  cout << dp[X];

  // maxPages[i][j] = max number of pages I can get considering the first i
  // books and spending at most j.
  // int n, x;
  // cin >> n >> x;
  // vector<int> h(n), s(n);
  // for (int& i : h)
  //   cin >> i;
  // for (int& i : s)
  //   cin >> i;
  // vector<vector<int>> maxPages(n + 1, vector<int>(x + 1));
  // for (int i = 1; i <= n; ++i) {
  //   for (int j = 1; j <= x; ++j) {
  //     maxPages[i][j] = maxPages[i - 1][j];
  //     if (h[i - 1] <= j) {
  //       maxPages[i][j] =
  //           max(maxPages[i][j], maxPages[i - 1][j - h[i - 1]] + s[i - 1]);
  //     }
  //   }
  // }
  // cout << maxPages[n][x];
}
