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

using namespace std;

#ifdef LOCAL
#include "../../_library/cc/debug.h"
#define FILE "test"
#else
#define debug(...) 0
#define FILE ""
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  vector<int> x(2);
  cin >> x[0] >> x[1];
  vector<vector<pair<int, int>>> changes(2);
  for (int j = 0; j < 2; ++j) {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
      int t;
      cin >> t;
      changes[j].emplace_back(t, j);
    }
  }

  if (x[0] > x[1]) {
    swap(x[0], x[1]);
    swap(changes[0], changes[1]);
    for (int i = 0; i < 2; ++i) {
      for (auto& [_, j] : changes[i]) {
        j = !j;
      }
    }
  }
  x[0] += 4;

  vector<pair<int, int>> mergedChanges(changes[0].size() + changes[1].size());
  merge(changes[0].begin(), changes[0].end(), changes[1].begin(),
        changes[1].end(), mergedChanges.begin());

  vector<bool> moving(2);
  int prev = 0;
  for (auto& [t, i] : mergedChanges) {
    if (moving[0] && !moving[1] && t - prev >= x[1] - x[0]) {
      cout << "bumper tap at time " << x[1] - x[0] + prev;
      return 0;
    }

    for (int j = 0; j < 2; ++j) {
      x[j] += moving[j] * (t - prev);
    }
    prev = t;
    moving[i] = !moving[i];
  }

  if (moving[0] && !moving[1]) {
    cout << "bumper tap at time " << (x[1] - x[0] + prev);
  } else {
    cout << "safe and sound";
  }
}
