#include <stdio.h>

#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <deque>
#include <fstream>
#include <functional>
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

  // Waste time on the cheapest roads
  int n;
  cin >> n;
  vector<int> tolls(n - 1), hours(n - 1);
  for (int &x : tolls) cin >> x;
  int _;
  cin >> _;
  for (int &x : hours) cin >> x;

  ll curHour = 0;
  ll ans = 0;
  int cheapest = 1e9;
  for (int i = 0; i < n - 1; ++i) {
    cheapest = min(cheapest, tolls[i]);
    ++curHour;
    ans += tolls[i];
    if (curHour < hours[i]) {
      ll delta = (hours[i] - curHour + 1) / 2;
      ans += cheapest * 2 * delta;
      curHour += delta * 2;
    }
  }
  cout << ans;
}
