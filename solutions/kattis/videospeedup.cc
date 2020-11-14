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

  int n, p, k;
  cin >> n >> p >> k;
  double orig = 0;
  int prev = 0;
  int cnt = 0;
  while (n--) {
    int t;
    cin >> t;
    orig += (t - prev) * (double)(100 + cnt * p) / 100;
    ++cnt;
    prev = t;
  }
  orig += (k - prev) * (double)(100 + cnt * p) / 100;
  cout << fixed << setprecision(6) << orig;
}
