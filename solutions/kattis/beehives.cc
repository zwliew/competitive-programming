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

  // N is small, so we can check the distance between every pair in O(N^2) time
  double d;
  int n;
  while (cin >> d >> n && (d || n)) {
    vector<pair<double, double>> hives(n);
    for (auto& [x, y] : hives) {
      cin >> x >> y;
    }

    vector<bool> sour(n);
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        double dx = hives[i].first - hives[j].first;
        double dy = hives[i].second - hives[j].second;
        if (dx * dx + dy * dy < d * d) {
          sour[i] = true;
          sour[j] = true;
        }
      }
    }

    int sourCnt = accumulate(sour.begin(), sour.end(), 0);
    cout << sourCnt << " sour, " << n - sourCnt << " sweet\n";
  }
}

