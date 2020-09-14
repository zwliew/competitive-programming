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
#define FILE "berries"
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  // Try 2 possible outermost jumps, then move 1 block at a time
  array<int, 3> x;
  cin >> x[0] >> x[1] >> x[2];
  sort(x.begin(), x.end());
  int ans = 0;
  if (x[1] < x[2] - 1) {
    ans = x[2] - x[1] - 1;
  }
  if (x[0] < x[1] - 1) {
    ans = max(ans, x[1] - x[0] - 1);
  }
  cout << ans;
}
