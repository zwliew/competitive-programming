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

  // Find the latest possible time slot for each person in descending order of
  // money.
  //
  // There are only 48 possible time slots so we can use a simple for-loop to
  // determine the latest possible time slot for each person.
  //
  // If there are more time slots, we can use disjoint sets to optimize.
  int n, t;
  cin >> n >> t;
  vector<pair<int, int>> persons(n);
  for (auto &[c, t] : persons) {
    cin >> c >> t;
  }
  sort(persons.rbegin(), persons.rend());
  int ans = 0;

  // bitset<48> times;
  // for (auto &[c, t] : persons) {
  //   for (int i = t; i >= 0; --i) {
  //     if (!times[i]) {
  //       times[i] = 1;
  //       ans += c;
  //       break;
  //     }
  //   }
  // }

  // Alternative optimized implementation using disjoint sets to determine the
  // latest possible time slot
  vector<int> parents(49);  // Parent of index i represents the latest possible,
                            // open time slot up through index (i - 1)
  iota(parents.begin(), parents.end(), 0);

  function<int(int)> find = [&](int idx) {
    return parents[idx] == idx ? idx : (parents[idx] = find(parents[idx]));
  };

  auto join = [&](int a, int b) { parents[find(b)] = find(a); };

  for (auto &[c, t] : persons) {
    int time = find(t + 1);
    if (time > 0) {
      join(time - 1, time);
      ans += c;
    }
  }

  cout << ans;
}
