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
#include <iterator>
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

  array<long double, 4> t;
  long double target;
  cin >> t[0] >> t[1] >> t[2] >> t[3] >> target;
  sort(t.begin(), t.end());

  long double first = (t[0] + t[1] + t[2]) / 3;
  long double second = (t[1] + t[2] + t[3]) / 3;
  if (second <= target) {
    cout << "infinite";
    return 0;
  }

  if (first > target) {
    cout << "impossible";
    return 0;
  }

  // (t[1] + t[2] + ans) / 3 <= target
  // target * 3 - t[1] - t[2] >= ans
  cout << fixed << setprecision(2) << target * 3 - t[1] - t[2];
}
