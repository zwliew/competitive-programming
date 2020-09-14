#include <algorithm>
#include <array>
#include <bitset>
#include <chrono>
#include <climits>
#include <cmath>
#include <cstring>
#include <deque>
#include <ext/pb_ds/assoc_container.hpp>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
//#include "bits/stdc++.h"

using namespace std;

#ifdef LOCAL
#include "../../_library/cc/debug.h"
#define FILE "test"
#else
#define debug(...) 0
#define FILE "helpcross"
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int c, n;
  cin >> c >> n;

  int ans = 0;
  vector<pair<int, int>> cows(n);

  // Iterate through the cows and find the first chicken >= cow.x
  // multiset<int> t;
  // for (int i = 0; i < c; ++i) {
  //   int x;
  //   cin >> x;
  //   t.insert(x);
  // }
  // for (int i = 0; i < n; ++i) {
  //   cin >> cows[i].second >> cows[i].first;
  // }
  // sort(cows.begin(), cows.end());
  // for (int i = 0; i < n; ++i) {
  //   auto it = t.lower_bound(cows[i].second);
  //   if (it != t.end() && *it <= cows[i].first) {
  //     ++ans;
  //     t.erase(it);
  //   }
  // }

  // Alternative: iterate through chickens and find the first cow with x <= t
  // and y >= t.
  vector<int> t(c);
  for (int i = 0; i < c; ++i) {
    cin >> t[i];
  }
  for (int i = 0; i < n; ++i) {
    cin >> cows[i].first >> cows[i].second;
  }
  sort(t.begin(), t.end());
  sort(cows.begin(), cows.end());
  multiset<int> ends;
  for (int i = 0, j = 0; i < c; ++i) {
    while (ends.size() && *ends.begin() < t[i]) {
      ends.erase(ends.begin());
    }
    while (j < n && cows[j].first <= t[i]) {
      if (cows[j].second >= t[i]) {
        ends.insert(cows[j].second);
      }
      ++j;
    }
    if (ends.size()) {
      ends.erase(ends.begin());
      ++ans;
    }
  }

  cout << ans;
}
