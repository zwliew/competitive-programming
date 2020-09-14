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

  // numWays[i][j] = numWays[i - 1][j] + numWays[i][j - 1] if grid[i][j] is not
  // a star
  const int mod = 1e9 + 7;
  int n;
  cin >> n;

  vector<int> numWays(n), nextNumWays(n);
  string x;
  numWays[0] = 1;
  for (int r = 0; r < n; ++r) {
    cin >> x;
    for (int c = 0; c < n; ++c) {
      if (x[c] == '.') {
        nextNumWays[c] = (numWays[c] + (c ? nextNumWays[c - 1] : 0)) % mod;
      } else {
        nextNumWays[c] = 0;
      }
    }
    numWays = nextNumWays;
  }
  cout << numWays[n - 1];
}
