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

  // Simulate the process.
  // The key observation is that the time one finishes depends on the time each
  // stage is free.
  int n, m;
  cin >> n >> m;
  vector<int> end(m);
  for (int i = 0; i < n; ++i) {
    int cur = 0;
    for (int j = 0; j < m; ++j) {
      int t;
      cin >> t;
      cur = max(cur, end[j]) + t;
      end[j] = cur;
    }
    cout << cur << ' ';
  }
}
