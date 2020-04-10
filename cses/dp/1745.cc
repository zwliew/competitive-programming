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

  int n;
  cin >> n;
  vector<int> x(n);
  for (int& i : x) cin >> i;
  vector<bitset<100001>> dp(n, bitset<100001>());
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 100001; ++j) {
      if (!j) {
        dp[i][j] = 1;
      } else if (!i) {
        dp[i][j] = j == x[0];
      } else {
        dp[i][j] = dp[i - 1][j];
        if (!dp[i][j] && j >= x[i]) {
          dp[i][j] = dp[i - 1][j - x[i]];
        }
      }
    }
  }
  vector<int> res;
  for (int i = 1; i <= 100000; ++i) {
    if (dp[n - 1][i]) res.push_back(i);
  }
  cout << res.size() << '\n';
  for (int i : res) {
    cout << i << ' ';
  }
}
