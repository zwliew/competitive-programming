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

  // Greedy interval covering
  ld a, b;
  while (cin >> a >> b) {
    int n;
    cin >> n;
    vector<tuple<ld, ld, int>> intervals;
    for (int i = 0; i < n; ++i) {
      ld s, e;
      cin >> s >> e;
      intervals.emplace_back(s, e, i);
    }
    sort(intervals.begin(), intervals.end());

    // Handle the case where the start and end points are the same separately
    if (a == b) {
      int found = -1;
      for (int i = 0; i < n; ++i) {
        if (get<0>(intervals[i]) <= a && get<1>(intervals[i]) >= b) {
          found = get<2>(intervals[i]);
          break;
        }
      }
      if (found != -1) {
        cout << "1\n" << found << '\n';
      } else {
        cout << "impossible\n";
      }
      continue;
    }

    ld prev = a;
    int i = 0;
    vector<int> ans;
    while (i < n && prev < b) {
      ld next = prev;
      int idx = i;
      while (i < n && get<0>(intervals[i]) <= prev) {
        if (get<1>(intervals[i]) > next) {
          next = get<1>(intervals[i]);
          idx = get<2>(intervals[i]);
        }
        ++i;
      }

      if (next == prev) {
        break;
      }

      ans.push_back(idx);
      prev = next;
    }

    if (prev < b) {
      cout << "impossible\n";
    } else {
      cout << ans.size() << '\n';
      for (int x : ans) {
        cout << x << ' ';
      }
      cout << '\n';
    }
  }
}
