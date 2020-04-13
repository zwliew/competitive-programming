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

  int a, b;
  cin >> a >> b;
  vector<vector<int>> minCuts(a + 1, vector<int>(b + 1, 1e9));
  for (int i = 0; i <= min(a, b); ++i) {
    minCuts[i][i] = 0;
  }
  for (int i = 1; i <= a; ++i) {
    for (int j = 1; j <= b; ++j) {
      if (i == j) continue;
      for (int k = 1; k < i; ++k) {
        minCuts[i][j] =
            min(minCuts[i][j], minCuts[k][j] + minCuts[i - k][j] + 1);
      }
      for (int k = 1; k < j; ++k) {
        minCuts[i][j] =
            min(minCuts[i][j], minCuts[i][k] + minCuts[i][j - k] + 1);
      }
    }
  }
  cout << minCuts[a][b];
}
