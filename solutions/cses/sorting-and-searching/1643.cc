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

  // Classical maximum subarray sum problem.
  // Solve with Kadane's algorithm.
  // https://en.wikipedia.org/wiki/Maximum_subarray_problem
  //
  // Can also solve using max(prefix sum [0, i] - min(prefix sum [0, j])) for
  // all i and j <= i.
  int n;
  cin >> n;
  ll ans = -1e10, cur = 0;
  while (n--) {
    int x;
    cin >> x;
    cur = max(0ll, cur) + x;
    ans = max(ans, cur);
  }
  cout << ans;

  // Alternative solution using prefix sums
  // int n;
  // cin >> n;
  // int64_t pref = 0;
  // int64_t minPref = 0;
  // int64_t ans = INT_MIN;
  // for (int i = 0; i < n; ++i) {
  //   int x;
  //   cin >> x;
  //   pref += x;
  //   ans = max(ans, pref - minPref);
  //   minPref = min(minPref, pref);
  // }
  // cout << ans;
}
