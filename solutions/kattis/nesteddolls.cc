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
// #include "bits/stdc++.h"

using namespace std;

#ifdef LOCAL
#include "../../_library/cc/debug.h"
#define FILE "test"
#else
#define debug(...) 0
#define FILE "cowjog"
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  // Sort in 1 dimension and LIS in the other.
  int t;
  cin >> t;
  while (t--) {
    int m;
    cin >> m;
    vector<pair<int, int>> a(m);
    for (auto& [w, h] : a) {
      cin >> w >> h;
    }
    sort(a.begin(), a.end(), [](auto& x, auto& y) {
      if (x.first == y.first)
        return x.second < y.second;
      return x.first > y.first;
    });

    vector<int> lis;
    for (int i = 0; i < m; ++i) {
      auto it = upper_bound(lis.begin(), lis.end(), a[i].second);
      if (it == lis.end()) {
        lis.push_back(a[i].second);
      } else {
        *it = a[i].second;
      }
    }

    cout << lis.size() << '\n';
  }
}
