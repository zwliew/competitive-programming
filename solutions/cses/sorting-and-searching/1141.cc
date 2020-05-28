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

  // Use a sliding window technique to maintain a contiguous subarray containing
  // distinct elements ending at each index, iteratively.
  int n;
  cin >> n;
  vector<int> x(n);
  for (int &i : x) cin >> i;
  int i = 0;
  set<int> s;
  int ans = 0;
  for (int j = 0; j < n; ++j) {
    while (s.count(x[j])) {
      s.erase(x[i]);
      ++i;
    }
    s.emplace(x[j]);
    ans = max(ans, (int)s.size());
  }
  cout << ans;
}
