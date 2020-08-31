#include <algorithm>
#include <array>
#include <bitset>
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

int dp(vector<vector<int>>& mem,
       vector<vector<int>>& prefixes,
       int p,
       int idx) {
  if (idx < 0)
    return 0;
  if (!p)
    return 0;
  if (p < 0)
    return -1e8;
  if (mem[p][idx] != -1)
    return mem[p][idx];
  int cur = 0;
  for (int i = 0; i <= min<int>(p, prefixes[idx].size() - 1); ++i) {
    cur = max(cur, dp(mem, prefixes, p - i, idx - 1) + prefixes[idx][i]);
  }
  return mem[p][idx] = cur;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int t;
  cin >> t;
  for (int ti = 1; ti <= t; ++ti) {
    int n, k, p;
    cin >> n >> k >> p;

    vector<vector<int>> mem(1501, vector<int>(51, -1));

    vector<vector<int>> prefixes(n, vector<int>(k + 1, 0));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < k; ++j) {
        int x;
        cin >> x;
        prefixes[i][j + 1] = prefixes[i][j] + x;
      }
    }

    cout << "Case #" << ti << ": " << dp(mem, prefixes, p, n - 1) << '\n';
  }

  // Iterative, bottom-up DP solution
  // int t;
  // cin >> t;
  // for (int ti = 1; ti <= t; ++ti) {
  //   int n, k, p;
  //   cin >> n >> k >> p;
  //   vector<vector<int>> beauty(n, vector<int>(k + 1));
  //   for (int i = 0; i < n; ++i) {
  //     for (int j = 1; j <= k; ++j) {
  //       cin >> beauty[i][j];
  //     }
  //     partial_sum(beauty[i].begin(), beauty[i].end(), beauty[i].begin());
  //   }
  //   vector<vector<int>> dp(n + 1, vector<int>(p + 1));
  //   for (int i = 1; i <= n; ++i) {
  //     for (int j = 1; j <= p; ++j) {
  //       for (int l = 0; l <= min(j, k); ++l) {
  //         dp[i][j] = max(dp[i][j], dp[i - 1][j - l] + beauty[i - 1][l]);
  //       }
  //     }
  //   }
  //   cout << "Case #" << ti << ": " << dp[n][p] << '\n';
  // }
}