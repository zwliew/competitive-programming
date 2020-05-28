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

  // Classical interval scheduling problem; sort by ending times and take
  // greedily.
  // https://en.wikipedia.org/wiki/Interval_scheduling#Greedy_polynomial_solution
  int n;
  cin >> n;
  vector<pair<int, int>> v(n);
  for (auto &[e, s] : v) {
    cin >> s >> e;
  }
  sort(v.begin(), v.end());
  int prevEnd = 0;
  int ans = 0;
  for (auto &[e, s] : v) {
    if (s < prevEnd) {
      continue;
    }
    prevEnd = e;
    ++ans;
  }
  cout << ans;
}
