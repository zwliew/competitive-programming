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

  // ways(i, j) = ways(i - 1, j) + ways(i, j - c[i])
  const int mod = 1e9 + 7;
  int n, x;
  cin >> n >> x;
  vector<int> c(n);
  for (int& i : c)
    cin >> i;
  vector<vector<int>> ways(n + 1, vector<int>(x + 1));
  ways[0][0] = 1;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= x; ++j) {
      ways[i][j] = ways[i - 1][j];
      if (c[i - 1] <= j) {
        ways[i][j] = (ways[i][j] + ways[i][j - c[i - 1]]) % mod;
      }
    }
  }
  cout << ways[n][x];
}
