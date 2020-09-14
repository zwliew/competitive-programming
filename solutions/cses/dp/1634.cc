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

  // minCoins[i] = the min number of coins needed to make a sum of i
  int n, x;
  cin >> n >> x;
  vector<int> minCoins(x + 1, 1e9);
  vector<int> c(n);
  for (int &i : c) cin >> i;
  minCoins[0] = 0;
  for (int i = 1; i <= x; ++i) {
    for (int j = 0; j < n; ++j) {
      if (c[j] <= i) {
        minCoins[i] = min(minCoins[i], minCoins[i - c[j]] + 1);
      }
    }
  }
  cout << (minCoins[x] >= 1e9 ? -1 : minCoins[x]);
}
