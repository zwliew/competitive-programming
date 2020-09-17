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
#define FILE ""
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  // Classical interval scheduling problem. Solved greedily.
  int n;
  cin >> n;
  vector<pair<int, int>> a(n);
  for (auto& [e, s] : a) {
    cin >> s >> e;
  }
  sort(a.begin(), a.end());

  int cnt = 0;
  int prev = 0;
  for (auto& [e, s] : a) {
    if (s >= prev) {
      ++cnt;
      prev = e;
    }
  }
  cout << cnt;
}
