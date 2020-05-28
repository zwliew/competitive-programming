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

  // Complete search for all possible values which satisfy the criteria
  int l, d, x;
  cin >> l >> d >> x;
  int cmin = 1e9, cmax = 0;
  for (int i = l; i <= d; ++i) {
    int sum = 0;
    int j = i;
    while (j) {
      sum += j % 10;
      j /= 10;
    }
    if (sum == x) {
      cmin = min(cmin, i);
      cmax = max(cmax, i);
    }
  }
  cout << cmin << '\n' << cmax;
}
