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

  int mod = 1e9 + 7;
  int n, m;
  cin >> n >> m;
  vector<int> x(n);
  for (int& i : x) cin >> i;

  // if !x[i] || x[i] == j,
  //    numArrays[i][j] = numArrays[i - 1][j - 1] + numArrays[i - 1][j] +
  //                      numArrays[i - 1][j + 1]
  // else,
  //    numArrays[i][j] = 0
  vector<vector<int>> numArrays(n, vector<int>(m + 1));
  for (int i = 1; i <= m; ++i) {
    numArrays[0][i] = (!x[0] || x[0] == i);
  }

  for (int i = 1; i < n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (!x[i] || x[i] == j) {
        numArrays[i][j] = (numArrays[i - 1][j - 1] + numArrays[i - 1][j]) % mod;
        if (j < m) {
          numArrays[i][j] = (numArrays[i][j] + numArrays[i - 1][j + 1]) % mod;
        }
      }
    }
  }

  int total = 0;
  for (int i = 1; i <= m; ++i) {
    total = (total + numArrays.back()[i]) % mod;
  }
  cout << total;
}
