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

  // Sort by starting temp and fit as many contiguous minions into a room as
  // possible.
  int n;
  cin >> n;
  vector<pair<int, int>> temps(n);
  for (auto &[s, e] : temps) cin >> s >> e;
  sort(temps.begin(), temps.end());
  int i = 0;
  int ans = 0;
  while (i < n) {
    int end = temps[i].second;
    while (i < n && temps[i].first <= end) {
      end = min(end, temps[i].second);
      ++i;
    }

    ++ans;
  }
  cout << ans;
}
