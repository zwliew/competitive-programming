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

  // The optimal solution is to distribute the sum of sections evenly across the
  // radiators. Simply simulate the process, greedily subtracting the ceiling of
  // average.
  int n;
  cin >> n;
  while (n--) {
    int c, sum;
    cin >> c >> sum;
    ll ans = 0;
    while (sum) {
      ll cur = (sum + c - 1) / c;
      sum -= cur;
      ans += cur * cur;
      --c;
    }
    cout << ans << '\n';
  }
}
