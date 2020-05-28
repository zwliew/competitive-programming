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

  // Replay all the events in sequential order and find the max number
  // of people in the restaurant at any time.
  int n;
  cin >> n;
  int ans = 0;
  vector<pair<int, int>> v;
  for (int i = 0; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    v.emplace_back(x, 1);
    v.emplace_back(y, -1);
  }
  sort(v.begin(), v.end());
  int cur = 0;
  for (auto &[t, e] : v) {
    cur += e;
    ans = max(ans, cur);
  }
  cout << ans;
}
